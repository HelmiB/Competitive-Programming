#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
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
    long long C(int n, int k){
        assert(n < maxn && k < maxn);
        //assert(n >= 0 && k >= 0);
        if(n < 0 || k < 0 || k > n) return 0;
        return mul(fact(n), inv(mul(fact(n - k), fact(k))));
    }
}math;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    long long ans = 0;
    if((n % 4) == 0){
        for(int i = 0 ; i < n ; ++i){
            long long x;
            cin >> x;
            ans = math.add(ans, math.mul(x, math.mul(math.C(n/2-1,i/2),(i%2?-1:1))));
        }
    }
    if((n % 4) == 1){
        for(int i = 0 ; i < n ; ++i){
            long long x;
            cin >> x;
            if(i % 2 == 0) ans = math.add(ans, math.mul(x, math.C(n/2,i/2)));
        }
    }
    if((n % 4) == 2){
        for(int i = 0 ; i < n ; ++i){
            long long x;
            cin >> x;
            ans = math.add(ans, math.mul(math.C(n/2 - 1,i/2), x));
        }
    }
    if((n % 4) == 3){
        for(int i = 0 ; i < n ; ++i){
            long long x;
            cin >> x;
            ans = math.add(ans, math.mul(math.C(n/2 - 1,i/2), x));
            if(i) ans = math.add(ans, math.mul(x, math.mul(math.C(n/2-1, (i-1)/2),(i%2?1:-1))));
        }
    }
    cout << ans << '\n';
    return 0;
}
