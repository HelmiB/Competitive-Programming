#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long long dp[350][350], C[350][350];
long long a[350];

struct DSU{
    int parent[maxn];
    int sz[maxn];
    int find_set(int v) {
        assert(v < maxn);
        if (v == parent[v])  return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }
    void init(int n){
        assert(n < maxn);
        for(int i = 0 ; i < n ; ++i)
            make_set(i);
    }
    void union_sets(int a, int b) {
        assert(a < maxn);
        assert(b < maxn);
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
}dsu;


struct Math{
    private: long long f[maxn];
    public:
    Math(){f[0] = 0;};
    long long add(long long x, long long y) { 
        x += y;
        if(x >= mod) x -= mod;
        if(x < 0) x += mod;
        return x;
    }
    long long mul(long long x, long long y) { return (add(x, mod) * add(y, mod)) % mod; }
    long long fast_pow(long long n, long long k){
            if(k == 0) return 1LL;
            long long ans = fast_pow(n, k >> 1);
            ans = mul(ans, ans);
            if(k & 1) ans = mul(n, ans);
            return ans;
    }
    long long inv(long long x) { return fast_pow(x, mod - 2); }
    void init_fact(){
        f[0] = 1LL;
        for(int i = 1 ; i < maxn ; ++i)
            f[i] = mul(i, f[i - 1]);
    }
    long long fact(int x){
        assert(x >= 0 && x < maxn);
        if(!f[0]) init_fact();
        return f[x];
    };
    long long Cc(int n, int k){
        if(k < 0 || k > n || n < 0) return 0;
        return C[n][k];
    }
}math;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    dsu.init(n);
    for(int i = 0 ; i < n ; ++i)
        for(int j = i + 1 ; j < n ; ++j){
            long long x = sqrt(a[i] * a[j]);
            if(x * x == a[i] * a[j]) dsu.union_sets(i, j);
        }
    vector < int > v;
    set < int > done;
    for(int i = 0 ; i < n ; ++i)
        if(done.find(dsu.find_set(i)) == done.end()){
            v.push_back(dsu.sz[dsu.find_set(i)]);
            done.insert(dsu.find_set(i));
        }
    int sm = 0;
    dp[0][0] = 1;
    C[0][0] = 1;
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 0 ; j <= i ; ++j){
            if(!j || j == i) C[i][j] = 1;
            else C[i][j] = math.add(C[i - 1][j - 1], C[i - 1][j]);
        }
    for(int i = 0 ; i < sz(v) ; ++i){
        for(int j = 0 ; j <= sm ; ++j){
            if(!dp[i][j]) continue;
            for(int s = 1 ; s <= min(v[i], sm + 1); ++s)
                for(int d = 0 ; d <= min(j, s); ++d)
                    dp[i + 1][j - d + v[i] - s] = math.add(dp[i + 1][j - d + v[i] - s], math.mul(dp[i][j],
                    math.mul(math.fact(v[i]), math.mul(math.Cc(j, d), math.mul(math.Cc(sm + 1 - j, s - d), math.Cc(v[i] - 1, s - 1))))));
        }
        sm += v[i];
    }
    cout << dp[sz(v)][0] << '\n';     
    return 0;
}
/*
0 : 1 4
1 : 2
1 4  
2 1 4
1 2 4
j = 1
*/

