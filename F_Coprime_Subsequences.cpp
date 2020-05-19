#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b));}
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int n, a[maxn], cnt[maxn], dp[maxn];

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
}math;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i], cnt[a[i]]++;
    for(int i = maxn - 1; i >= 1 ; --i){
        int ad = 0, sub = 0;
        for(int j = i; j < maxn ; j += i){
            ad += cnt[j];
            sub = math.add(sub, dp[j]);
        }
        dp[i] = math.add(math.add(math.fast_pow(2, ad), -1), -sub);
    }
    cout << dp[1] << '\n';
    return 0;
}

// 3 * 4, 1 * 8, 1 * 2, 1 * 2, 1
// 127 - 12 - 8 - 2 - 2 - 1