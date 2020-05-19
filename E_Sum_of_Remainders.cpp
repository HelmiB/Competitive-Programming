#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

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

long long brute(int n, int m){
    long long ans = 0;
    for(int i = 1 ; i <= m ; ++i) ans += n % i, ans %= mod;
    return ans;
}

long long tw = fast_pow(2, mod - 2);

long long get(long long x){
    return mul(x, mul(x + 1, tw));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n, m;
    cin >> n >> m;
    long long ans = (m > n ? mul(m - n, n):0);
    long long prv = 1;
    for(long long i = 2 ; i * i <= n ; ++i){
        long long a = n / i + 1, b = min(m, n / (i - 1));
        prv = i;
        if(b < a) continue;
        b %= mod, a %= mod;
        long long ad = add(get(b), -get(a - 1));
        ans = add(ans, add(mul(b - a + 1, n % mod), mul(1 - i, ad)));
    }
    for(long long i = 2 ; i <= n / prv ; ++i){
        if(i > m) break;
        ans = add(ans, n % i);
    }
    cout << ans <<  '\n';
    return 0;
}
