#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 3000500;
const int mod = 1e9 + 7;
vector < int > sizes;
int occ[maxn], cnt[maxn], invx[maxn];

struct Math{
    private: long long f[maxn];
    public:
    Math(){f[0] = 0;};
    long long add(long long x, long long y) { 
        x += y;
        if(x >= mod) x -= mod;
        if(x < 0) x += mod;
        if(x < 0 || x >= mod) x = (x + mod) % mod;
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
    long long inv(long long x) { return invx[x]; }
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
    int C(int n, int k){
        if(n < k) return 0;
        assert(n < maxn && k > 0);
        return mul(fact(n), inv(mul(fact(k), fact(n - k))));
    }
    int cat(int n){
        if(!n) return 1;
        return mul(C(2 * n, n), inv(n + 1));
    }
}math;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(occ, -1, sizeof occ);
    invx[1] = 1;
    for(int i = 2; i < maxn; ++i)
        invx[i] = (mod - (mod/i) * invx[mod%i] % mod) % mod;
    int n;
    cin >> n;
    vector < int > v(n);
    for(auto &x : v) cin >> x;
    stack < pair < int, int > > stk;
    for(int i = 0 ; i < n ; ++i){
        while(sz(stk) && stk.top().second >= v[i]) stk.pop();
        int L = (sz(stk) ? stk.top().first:-1);
        if(~occ[v[i]] && occ[v[i]] < L){
            sizes.push_back(cnt[v[i]]);
            cnt[v[i]] = 1;
        }else if(~occ[v[i]]){
            cnt[v[i]]++;
        }else{
            cnt[v[i]] = 1;
        }
        occ[v[i]] = i;
        stk.push({i, v[i]});
    }
    for(int i = 0 ; i < maxn ; ++i)
        if(cnt[i])
            sizes.push_back(cnt[i]);
    int ans = 1;
    for(auto x : sizes)
        ans = math.mul(ans, math.cat(x));
    
    cout << ans << '\n';
    return 0;
}