#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < pair < int, int > > g[maxn];
int sz[maxn];
struct edge{
    int u, v;
    int sz, w;
}ed[maxn];
int n;

long double calc(int i){
    int sz = ed[i].sz;
    return ed[i].w * 6.0 *
    (long double)((n - sz) * sz * (sz - 1) +
     sz * (n - sz) * (n - sz - 1)) / (long double) (n * (n - 1) * (n - 2));
}

void init(int u = 0, int p = -1){
    sz[u] = 1;
    for(auto v : g[u])
        if(v.first != p){ 
            init(v.first, u);
            ed[v.second].sz = sz[v.first];
            sz[u] += sz[v.first];
        }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n - 1 ; ++i){
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
        ed[i].u--; ed[i].v--;
        g[ed[i].u].push_back({ed[i].v, i});
        g[ed[i].v].push_back({ed[i].u, i});
    }
    init();
    long double ans = 0;
    for(int i = 0 ; i < n - 1 ; ++i)
        ans += calc(i);
    int q;
    cin >> q;
    while(q--){
        int r, w;
        cin >> r >> w;
        --r;
        ans -= calc(r);
        ed[r].w = w;
        ans += calc(r);
        cout << fixed << setprecision(10) << ans << '\n';
    }
    return 0;
}
