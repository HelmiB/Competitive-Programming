#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1010;
const int mod = 1e9 + 7;
int dp[maxn][maxn];
int inv_pw[maxn][maxn];
int n, a, b, c, d;
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
}math;

int solve(int i, int sz){
    if(i == n) return math.fact(n);
    if(sz > b) return 0;
    int &ret = dp[i][sz];
    if(~ret) return ret;
    ret = solve(i, sz + 1);
    if(i + c * sz > n) return ret;
    int j = i + c * sz, ng = c;
    int p = inv_pw[sz][c];
    while(j <= n && ng <= d){
        ret = math.add(ret, math.mul(inv_pw[ng][1], math.mul(p, solve(j, sz + 1))));
        p = math.mul(p, inv_pw[sz][1]);
        ng++;
        j += sz;
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 0 ; i < maxn ; ++i){
        inv_pw[i][0] = 1;
        inv_pw[i][1] = math.inv(math.fact(i));
        for(int j = 2 ; j < maxn ; ++j)
            inv_pw[i][j] = math.mul(inv_pw[i][j - 1], inv_pw[i][1]);
    }
    cin >> n >> a >> b >> c >> d;
    memset(dp, -1, sizeof dp);
    cout << solve(0, a) << '\n';
    return 0;
}