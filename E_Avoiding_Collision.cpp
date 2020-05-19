#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < pair < int, int > > g[maxn];
vector < pair < int, pair < int, bool > > > gr[maxn];
int paths[2][maxn], d[2][maxn];
bool vis[maxn];
int n, m, s, t;

set < pair < int, int > > in;

void dij(int idx, int st){
    for(int i = 0 ; i < n ; ++i) d[idx][i] = 1e18;
    d[idx][st] = 0;
    priority_queue < pair < int, int > > pq;
    pq.push({0, st});
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        if(d[idx][u.second] > -u.first) continue;
        for(auto v : g[u.second])
            if(d[idx][v.first] > d[idx][u.second] + v.second){
                d[idx][v.first] = d[idx][u.second] + v.second;
                pq.push({-d[idx][v.first], v.first});
            }
    }
}

long long add(long long x, long long y) { 
    return (x + y + mod) % mod;
}
long long mul(long long x, long long y) { return (add(x, mod) * add(y, mod)) % mod; }


int tot_w;
void build_paths(int idx, int st){
    paths[idx][st] = 1;
    set < pair < int, int > > s;
    s.insert({0, st});
    while(!s.empty()){
        auto u = *s.begin();
        s.erase(u);
        for(auto v : g[u.second])
            if(d[idx][u.second] + v.second + d[1 - idx][v.first] == tot_w){
                paths[idx][v.first] = add(paths[idx][v.first], paths[idx][u.second]);
                in.insert({min(u.second, v.first), max(u.second, v.first)});
                s.insert({d[idx][v.first], v.first});
            }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    cin >> s >> t;
    --s; --t;
    for(int i = 0 ; i < m ; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dij(0, s);
    dij(1, t);
    tot_w = d[1][s];
    build_paths(0, s);
    build_paths(1, t);
    assert(paths[0][t] == paths[1][s]);
    int ans = mul(paths[0][t], paths[0][t]);
    for(int u = 0 ; u < n ; ++u){
        assert(paths[0][u] >= 0);
        assert(paths[1][u] >= 0);
        if(d[1][u] + d[0][u] == tot_w && d[1][u] == d[0][u]){
            ans = add(ans, -mul(paths[0][u], paths[1][u]) * mul(paths[0][u], paths[1][u]));
            continue;
        }
        set < pair < int, int > > ed;
        for(auto v : g[u])
            if((d[0][u] + v.second + d[1][v.first]) == tot_w){
                if(in.find({min(u, v.first), max(u, v.first)}) == in.end())
                    continue;
                in.erase({min(u, v.first), max(u, v.first)});
                int t1 = d[0][u];
                int t2 = d[1][v.first];
                if(abs(t1 - t2) < v.second) 
                    ans = add(ans,
                     -mul(mul(paths[0][u], paths[1][v.first]), mul(paths[0][u], paths[1][v.first])));
        }
    }
    cout << ans << '\n';
    return 0;
}

//201260731