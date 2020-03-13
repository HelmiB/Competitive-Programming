#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
vector < int > g[maxn];
int a[maxn], ans[maxn], sz[maxn];

void init(int u = 1, int p = 0){
    sz[u] = a[u];
    for(auto v : g[u])
        if(p != v){
            init(v, u);
            if(sz[v] > 0) sz[u] += sz[v];
        }
}

void solve(int u = 1, int p = 0, int sm = 0){
    sm = max(sm, 0);
    ans[u] = sz[u] + sm;
    for(auto v : g[u])
        if(v != p)
            if(sz[v] > 0)
                sm += sz[v];
    sm += a[u];
    for(auto v : g[u])
        if(v != p){
            if(sz[v] > 0) sm -= sz[v];
            solve(v, u, sm);
            if(sz[v] > 0) sm += sz[v];
        }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i], a[i] = (!a[i] ? -1:a[i]);
    for(int i = 0 ; i < n - 1 ; ++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init();
    solve();
    for(int i = 1 ; i <= n ; ++i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
