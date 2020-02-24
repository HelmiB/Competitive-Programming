#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1000500;
const int mod = 1e9 + 7;
int n, l1, l2;
vector < pair < int, int > > g[maxn];
long long dist[maxn];


void build(int off, int node, int lo, int hi){
    if(lo == hi){
        if(off < l2) g[off + node].push_back({lo, 0});
        else g[lo].push_back({off + node, 0});
        return;
    }
    int mid = (lo + hi) >> 1;
    build(off, 2 * node + 1, lo, mid);
    build(off, 2 * node + 2, mid + 1, hi);
    if(off < l2){
        g[off + node].push_back({off + 2 * node + 1, 0});
        g[off + node].push_back({off + 2 * node + 2, 0});
    }else{
        g[off + 2 * node + 1].push_back({off + node, 0});
        g[off + 2 * node + 2].push_back({off + node, 0});
    }
}

void update(int off, int node, int lo, int hi, int ql, int qh, int v, int w){
    if(ql > hi || qh < lo || lo > hi) return;
    if(ql <= lo && hi <= qh){
        if(off < l2) g[v].push_back({off + node, w});
        else g[off + node].push_back({v, w});
        return;
    }
    int mid = (lo + hi) >> 1;
    update(off, 2 * node + 1, lo, mid, ql, qh, v, w);
    update(off, 2 * node + 2, mid + 1, hi, ql, qh, v, w);
}

void dij(int s){
    
    for(int i = 0 ; i < l2 + 4 * maxn / 10 ; ++i) dist[i] = 1e18;
    dist[s] = 0;
    priority_queue < pair < long long, int > > pq;
    pq.push({0, s});
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        if(dist[u.second] < -u.first) continue;        
        for(auto v : g[u.second])
            if(dist[u.second] + v.second < dist[v.first]){
                dist[v.first] = dist[u.second] + v.second;
                pq.push({-dist[v.first], v.first});
            }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q, s;
    cin >> n >> q >> s;
    l1 = n + 1, l2 = l1 + 4 * maxn / 10 + 1;
    build(l1, 0, 0, n - 1);
    build(l2, 0, 0, n - 1);
    for(int i = 0 ; i < q ; ++i){
        int t;
        cin >> t;
        if(t == 1){
            int v, u, w;
            cin >> v >> u >> w;
            --v; --u;
            g[v].push_back({u, w});
        }
        if(t == 2){
            int l, r, v, w;
            cin >> v >> l >> r >> w;
            --v; --l; --r;
            update(l1, 0, 0, n - 1, l, r, v, w);
        }
        if(t == 3){
            int l, r, v, w;
            cin >> v >> l >> r >> w;
            --v; --l; --r;
            update(l2, 0, 0, n - 1, l, r, v, w);
        }
    }
    dij(s - 1);
    for(int i = 0 ; i < n ; ++i) cout << (dist[i] == 1e18 ? -1:dist[i]) << ' ';
    cout << '\n';
    return 0;
}
