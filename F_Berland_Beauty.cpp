#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < pair < int, int > > g[5010];
vector < pair < pair < int, int > , int > > q;
struct edge{
    int u, v, w;
}ed[5010];
int p[5010], level[5010];

void init(int u = 0, int pr = -1, int lvl = 0){
    p[u] = pr;
    level[u] = lvl + 1;
    for(auto v : g[u])
        if(v.second != pr)
            init(v.first, v.second, lvl + 1);
}

void process(int u , int v, int w){
        if(level[u] < level[v]) swap(u,v);
        while(level[u] != level[v]){
            ed[p[u]].w = max(ed[p[u]].w, w);
            u = (ed[p[u]].u == u ? ed[p[u]].v:ed[p[u]].u);
        }    
        if(u == v) return;
        while(u != v){
            ed[p[u]].w = max(ed[p[u]].w, w);
            ed[p[v]].w = max(ed[p[v]].w, w);
            u = (ed[p[u]].u == u ? ed[p[u]].v:ed[p[u]].u);
            v = (ed[p[v]].u == v ? ed[p[v]].v:ed[p[v]].u);
        }
}

bool solve(int u , int v, int w){
        if(level[u] < level[v]) swap(u,v);
        int d = 1e9;
        while(level[u] != level[v]){
            d = min(d, ed[p[u]].w);
            u = (ed[p[u]].u == u ? ed[p[u]].v:ed[p[u]].u);
        }    
        if(u == v) return d == w;
        while(u != v){
            d = min(d, ed[p[u]].w);
            d = min(d, ed[p[v]].w);
            u = (ed[p[u]].u == u ? ed[p[u]].v:ed[p[u]].u);
            v = (ed[p[v]].u == v ? ed[p[v]].v:ed[p[v]].u);
        }
        return d == w;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n - 1; ++i){
        cin >> ed[i].u >> ed[i].v;
        ed[i].u--; ed[i].v--;
        g[ed[i].u].push_back({ed[i].v, i});
        g[ed[i].v].push_back({ed[i].u, i});
    }
    init();
    int m;
    cin >> m;
    for(int i = 0 ; i < m ; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        q.push_back({{u, v}, w});
        process(u, v, w);
    }
    for(int i = 0 ; i < m ; ++i){
        int u = q[i].first.first;
        int v = q[i].first.second;
        int w = q[i].second;
        if(!solve(u, v, w)) return cout << -1 << '\n', 0;
    }
    for(int i = 0 ; i < n - 1 ; ++i) cout << max(1, ed[i].w) << ' ';
    cout << '\n';
    return 0;
}
