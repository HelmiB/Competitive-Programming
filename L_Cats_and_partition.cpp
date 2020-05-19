#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
long long a[maxn], dp[maxn];
int nxt[maxn], n, y;

struct Math{
    private: long long f[maxn];
    public:
    Math(){f[0] = 0;};
    long long add(long long x, long long y) { 
        x += y;
        x %= mod;
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
    long long C(long long n, long long k){
    if(k > n) return 0;
    return mul(fact(n), inv(mul(fact(k), fact(n - k))));
}
}math;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> y;
    for(int i = 0 ; i < n ; ++i) cin >> a[i], nxt[i] = n;
    priority_queue < pair < int , int > > mn, mx;
    for(int i = 0 ; i < n ; ++i){
        while(!mn.empty() && a[i] + mn.top().first > y){
            nxt[mn.top().second] = min(nxt[mn.top().second], i);
            mn.pop();
        }
        while(!mx.empty() && mx.top().first - a[i] > y){
            nxt[mx.top().second] = min(nxt[mx.top().second], i);
            mx.pop();
        }
        mn.push({-a[i], i});
        mx.push({a[i], i});
    }
    dp[n] = 1;
    for(int i = n - 2 ; i >= 0 ; --i) nxt[i] = min(nxt[i], nxt[i + 1]);
    for(int i = n - 1 ; i >= 0 ; --i){
        dp[i] = math.add(dp[i + 1], -dp[nxt[i] + 1] + mod);
        dp[i] = math.add(dp[i], dp[i + 1]);
    }
    cout << math.add(dp[0], -dp[1] + mod)  << '\n';
    return 0;
}