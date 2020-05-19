#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

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
}math;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long a, b, n, x;
    cin >> a >> b >> n >> x;
    if(a == 1) return cout << math.add(x, math.mul(n, b)) << '\n', 0;
    cout << math.add(math.mul(math.fast_pow(a, n), x),
     math.mul(b, math.mul(math.add(math.fast_pow(a, n), -1), math.inv(a - 1 + mod)))) << '\n';

    return 0;
}