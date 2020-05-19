#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 998244353;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b));}

struct Math{
    long long f[maxn], invT[maxn];
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
    long long inv(long long x) { return invT[x]; }
    void init_fact(){
        f[0] = invT[0] = 1LL;
        for(int i = 1 ; i < maxn ; ++i){
            f[i] = mul(i, f[i - 1]);
            invT[i] = fast_pow(f[i], mod - 2);
        }
    }
    long long fact(int x){
        assert(x >= 0 && x < maxn);
        if(!f[0]) init_fact();
        return f[x];
    };
}math;

vector < int > pr;
long long solve(int a, int b){
    if(a < b) swap(a, b);
    a = a / b;
    int ad = 0;
    map < int, int > cnt;
    for(auto p : pr) 
        while(a % p == 0)
            cnt[p]++, ad++, a /= p;
    if(a > 1) cnt[a]++, ad++;
    long long ans = math.fact(ad);
    for(auto x : cnt) ans = math.mul(ans, math.inv(x.second));
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int d, q;
    cin >> d;
    for(int i = 2 ; i * i <= d ; ++i)
        if(d % i == 0){ 
            pr.push_back(i);            
            while(d % i == 0) d /= i;
        }
    if(d > 1) pr.push_back(d);
    cin >> q;
    while(q--){
        long long a, b;
        cin >> a >> b;
        cout << math.mul(solve(a, gcd(a, b)), solve(gcd(a, b), b)) << '\n';
    }

    return 0;
}