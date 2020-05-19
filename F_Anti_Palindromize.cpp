#include<bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll INF = numeric_limits<ll>::max() / 4;
typedef vector<ll> VL;
struct MCMF {
    int N;
    vector<vi> ed, red;
    vector<VL> cap, flow, cost;
    vi seen;
    VL dist, pi;
    vector<pii> par;
    MCMF(int N) :
        N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
        seen(N), dist(N), pi(N), par(N) {}
    void addEdge(int from, int to, ll cap, ll cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
        ed[from].push_back(to);
        red[to].push_back(from);
    }
    void path(int s) {
        fill(all(seen), 0);
        fill(all(dist), INF);
        dist[s] = 0; ll di;
        __gnu_pbds::priority_queue<pair<ll, int>> q;
        vector<decltype(q)::point_iterator> its(N);
        q.push({0, s});
        auto relax = [&](int i, ll cap, ll cost, int dir) {
            ll val = di - pi[i] + cost;
            if (cap && val < dist[i]) {
                dist[i] = val;
                par[i] = {s, dir};
                if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
                else q.modify(its[i], {-dist[i], i});
            }
        };
        while (!q.empty()) {
            s = q.top().second; q.pop();
            seen[s] = 1; di = dist[s] + pi[s];
            trav(i, ed[s]) if (!seen[i])
            relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
            trav(i, red[s]) if (!seen[i])
            relax(i, flow[i][s], -cost[i][s], 0);
        }
        rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
    }
    pair<ll, ll> maxflow(int s, int t) {
    ll totflow = 0, totcost = 0;
    while (path(s), seen[t]) {
        ll fl = INF;
        for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
        fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);

        totflow += fl;
        for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
        if (r) flow[p][x] += fl;
        else flow[x][p] -= fl;
    }
    rep(i,0,N) rep(j,0,N) totcost += cost[i][j] * flow[i][j];
    return {totflow, totcost};
    }
    // I f some costs can be negative , c a l l th is before maxflow :
    void setpi(int s) { // (otherwise , leave th is out)
    fill(all(pi), INF); pi[s] = 0;
    int it = N, ch = 1; ll v;
    while (ch-- && it--)
    rep(i,0,N) if (pi[i] != INF)
    trav(to, ed[i]) if (cap[i][to])
    if ((v = pi[i] + cost[i][to]) < pi[to])
    pi[to] = v, ch = 1;
    assert(it >= 0); // negative cost cyc le
    }
};

string s;
vector < int > b;
int n;
int get(int i, int j, int k){
    return (s[i] == (char)(j + 'a') ? -b[i]:0)
         + (s[n - i - 1] == (char)(k + 'a') ? -b[n - i - 1]:0);
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    cin >> s;
    b.resize(n);
    for(auto &x : b) cin >> x;
    int cur = 0;
    MCMF mcmf(2 + n / 2 + 26);
    for(int i = 0 ; i < n / 2 ; ++i)
        for(int j = 0 ; j < 26 ; ++j){
            int cost = cost = max((s[i] == (char)(j + 'a') ? b[i]:0),
                     (s[n - i - 1] == (char)(j + 'a') ? b[n - i - 1]:0));
            mcmf.addEdge(j + 1, 26 + i + 1, 1, -cost);            
        }
    for(int i = 0 ; i < n / 2 ; ++i)
        mcmf.addEdge(26 + i + 1, 1 + n / 2 + 26, 2, 0);
    for(int j = 0 ; j < 26 ; ++j){
        int ad = 0;
        for(auto c : s) ad += (c - 'a') == j;
        if(!ad) continue;
        mcmf.addEdge(0, j + 1, ad, 0);
    }
    mcmf.setpi(0);
    cout << -mcmf.maxflow(0, 1 + n / 2 + 26).second << '\n';
    return 0;
}