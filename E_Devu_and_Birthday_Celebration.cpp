#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 400500;
const int mod = 1e9 + 7;
long long dp[maxn];
vector < int > dv[maxn];

struct Math{
    private: long long f[maxn];
    public:
    Math(){f[0] = 0;};
    long long add(long long x, long long y) {
        return (x + y + mod) % mod;
    }
    long long mul(long long x, long long y) { return (x % mod * y % mod) % mod; }
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
    long long C(int n, int k){
        if(k > n) return 0;
        return mul(fact(n), inv(mul(fact(k), fact(n - k))));
    }
}math;


long long get(int n, int f, int d){
    int rem = n / d;
    if(rem < f) return 0;
    rem -= f;
    return math.add(math.C(f + rem - 1, f - 1), -math.C(rem - 1, f - 1));
}

int n, f, idx;
int vis[maxn];
long long solve(int u){
    long long &ret = dp[u];
    if(vis[u] == idx) return ret;
    vis[u] = idx;
    long long ans = math.C(u - 1, f - 1);
    for(int i = 0 ; i < sz(dv[u]) ; ++i){
        if(i) ans = math.add(ans, -solve(u / dv[u][i]));
        if(dv[u][i] != u / dv[u][i]) ans = math.add(ans, -solve(dv[u][i]));
    }
    return ret = ans;
}

struct MillerRabin{
    long long mul(long long a,long long b,long long mod){
        long long res = 0, y = a % mod;
        while(b > 0){
            if(b & 1) res = (res + y) % mod;
            y = (y * 2) % mod;
            b >>= 1;
        }
        return res % mod;
    }
    long long fast_pow(long long n, long long k, long long mod){
            if(k == 0) return 1LL;
            long long ans = fast_pow(n, k >> 1, mod);
            ans = mul(ans, ans, mod);
            if(k & 1) ans = mul(n, ans, mod);
            return ans;
    }
    bool check_composite(long long n, long long a, long long d, int s){
        long long x = fast_pow(a, d, n);
        if (x == 1 || x == n - 1)
            return false;
        for (int r = 1; r < s; r++) {
            x = mul(x, x, n);
            if (x == n - 1)
                return false;
        }
        return true;
    }
    bool check(long long n) { // returns true if n is prime, else returns false.
        if (n < 2)
            return false;
        int r = 0;
        long long d = n - 1;
        while ((d & 1) == 0) {
            d >>= 1;
            r++;
        }
        for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
            if (n == a)
                return true;
            if (check_composite(n, a, d, r))
                return false;
        }
        return true;
    }
}mr;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 1 ; i < maxn / 4 ; ++i)
        for(int j = 1 ; j * j <= i ; ++j)
            if(i % j == 0)
                dv[i].push_back(j);
    int t;
    cin >> t;
    idx = 1;
    map < pair < int, int > , int > st;
    while(t--){
        cin >> n >> f;
        if(st.count({n, f})){
            cout << st[{n, f}] << '\n';
            continue;
        }
        cout << solve(n) << '\n';
        st[{n, f}] = solve(n);
        idx++;
    }
    return 0;
}