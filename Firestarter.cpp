#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
vector < pair < int, int > > g[maxn];
int nxt, n, m, q;
struct ed{
    int u, v, w;
}e[maxn];
vector < pair < int, int > > qs[maxn];
long long dist[maxn];

void dij(){
    for(int i = 0 ; i < nxt ; ++i) dist[i] = 1e18;
    dist[0] = 0;
    priority_queue < pair < long long, int > > pq;
    pq.push({0, 0});
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        if(-u.first > dist[u.second]) continue;
        for(auto v : g[u.second])
            if(dist[u.second] + v.second < dist[v.first]){
                dist[v.first] = dist[u.second] + v.second;
                pq.push({-dist[v.first], v.first});
            }
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    map < pair < int, int > , int > id;
    for(int i = 0 ; i < m ; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        if(u > v) swap(u, v);
        id[{u, v}] = i;
        e[i].u = u;
        e[i].v = v;
        e[i].w = w;
    }
    nxt = n + 1;
    while(q--){
        int t, u, v, x;
        cin >> t >> u >> v >> x;
        int idx = id[{min(u, v), max(u, v)}];
        if(u > v) x = e[idx].w - x, swap(u, v);
        if(!x){
            g[0].push_back({u, t});
            g[u].push_back({0, t});
            continue;
        }
        if(x == e[idx].w){
            g[0].push_back({v, t});
            g[v].push_back({0, t});
            continue;
        }
        qs[idx].push_back({x, t});
    }
    for(int i = 0 ; i < m ; ++i){
        sort(all(qs[i]));
        int prv = e[i].u, w = 0;
        for(auto x : qs[i]){
            if(x.first == w) continue;
            int idx = nxt++;
            g[prv].push_back({idx, x.first - w});
            g[idx].push_back({prv, x.first - w});
            g[0].push_back({idx, x.second});
            g[idx].push_back({0, x.second});
            prv = idx;
            w = x.first;  
        }
        g[prv].push_back({e[i].v, e[i].w - w});
        g[e[i].v].push_back({prv, e[i].w - w});
    }
    dij();
    long double ans = 0;
    for(int i = 1 ; i < nxt ; ++i)
        for(auto v : g[i]){
            if(!v.first) continue;
            int a = dist[i];
            int b = dist[v.first];
            int w = v.second;
            if(a > b) swap(a, b);
            long double T = min(w, b - a);
            T += (long double)(w - T) / 2.0;
            //cout << i << ' ' << v.first << ' ' << b - a << '\n';
            ans = max(ans, T + a);
        }
    cout << fixed << setprecision(1) << ans << '\n';
    return 0;
}