#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 300500;
const int mod = 1e9 + 7;
vector < int > g[maxn];
int p[maxn], dep[maxn], under[maxn], sz[maxn];
set < pair < pair < int, int >, int > > st;

void init(int u = 0, int pr = -1){
    p[u] = pr;
    if(~p[u]) dep[u] = 1 + dep[p[u]];
    sz[u] = 1;
    for(auto v : g[u])
        if(v != pr){
            init(v, u);
            sz[u] += sz[v];
        }
    under[u] = dep[u] - sz[u] + 1;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i < n - 1 ; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init();
    sort(under, under + n);
    reverse(under, under + n);
    int ans = 0;
    for(int i = 0 ; i < k ; ++i) ans += under[i];
    cout << ans << '\n';
    return 0;
}