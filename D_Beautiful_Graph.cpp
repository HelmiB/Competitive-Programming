#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 998244353;
vector < int > g[maxn];
int od, ev;
bool vis[maxn], pr[maxn];

long long add(long long x, long long y) { 
    return (x + y + mod) % mod;
}
long long mul(long long x, long long y) { return (add(x, mod) * add(y, mod)) % mod; }

long long fast_pow(long long n, long long k){
        if(k == 0) return 1LL;
        long long ans = fast_pow(n, k >> 1);
        ans = mul(ans, ans);
        if(k & 1) ans = mul(n, ans);
        return ans;
}

bool dfs(int u, bool par){
    if(vis[u]) return pr[u] == par;
    vis[u] = true;
    pr[u] = par;
    od += par;
    ev += 1 - par;
    bool can = true;
    for(auto v : g[u])
        can &= dfs(v, 1 - par);
    return can;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0 ; i < n ; ++i) g[i].clear();
        memset(vis, false, n * sizeof vis[0]);
        memset(pr, false, n * sizeof pr[0]);
        for(int i = 0 ; i < m ; ++i){
            int u, v;
            cin >> u >> v;
            --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = 1;
        for(int i = 0 ; i < n ; ++i)
            if(!vis[i]){
                od = ev = 0;
                bool can = dfs(i, 0);
                if(!can){
                    ans = 0;
                    break;
                }
                ans = mul(ans, add(fast_pow(2, od), fast_pow(2, ev)));
            }
        cout << ans << '\n';
    }

    return 0;
}