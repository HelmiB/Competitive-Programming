#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int l[maxn], dp[maxn];

long long ad(long long x, long long y) { 
        return (x + y + mod) % mod;
}
long long mul(long long x, long long y) { return (ad(x, mod) * ad(y, mod)) % mod; }

struct BIT{
    private: long long tree[maxn + 10];
    public:
    void add(int x, long long v){for(x++; x < maxn; x += x & -x)tree[x] = ad(tree[x], v) ;}
    long long get(int x){long long ret = 0; for(x++; x; x -= x & -x)ret = ad(ret, tree[x]); return ret;}
    int range(int l, int r){
        if(l > r) return 0;
        return ad(get(r), -(l ? get(l - 1):0));
    }
}bit;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1 ; i <= n ; ++i) l[i] = maxn;
    for(int i = 0 ; i < q ; ++i){
        int a, b;
        cin >> a >> b;
        l[a] = min(l[a], b);
    }
    dp[n + 1] = 1;
    int nxt = n + 1;
    for(int i = n ; i >= 0 ; --i){
        nxt = min(nxt, l[i]);
        dp[i] = bit.range(i + 1, nxt);
        bit.add(i, dp[i]);
    }
    cout << dp[0] << '\n';
    return 0;
}