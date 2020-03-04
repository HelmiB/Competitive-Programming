#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int dist[2][110];
long double dp[110];
long long sz[110], in[110], out[110];
vector < int > g[maxn];
bool vis[2][maxn];
int n, m;

void calc1(int u = 0){
    if(vis[0][u]) return;
    vis[0][u] = true;
    if(dist[0][u] + dist[1][u] != dist[1][0]) return;
    for(auto v : g[u])
        if(dist[1][u] == 1 + dist[1][v]){
            calc1(v);
            out[u] += out[v];
        }
}

void calc2(int u = n - 1){
    if(vis[1][u]) return;
    vis[1][u] = true;
    for(auto v : g[u])
    if(dist[1][u] + 1 == dist[1][v]){
        calc2(v);
        in[u] += in[v];
    }
}

long double solve(int u){
    if(u == n - 1) return 1;
    long double &ret = dp[u];
    if(ret > 0) return ret;
    if(dist[0][u] + dist[1][u] != dist[1][0]) return 0 ;
    long double best = (!u ? 1:(long double)(2.0 * sz[u]) / (long double)sz[n - 1]);
    for(auto v : g[u])
        if(dist[1][u] == 1 + dist[1][v])
            best = max(best, solve(v));
    return ret = best;
}

void bfs(int idx, int st){
    for(int i = 0 ; i < n ; ++i) dist[idx][i] = maxn;
    dist[idx][st] = 0;
    queue < int > q;
    q.push(st);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : g[u])
            if(dist[idx][v] > dist[idx][u] + 1){
                dist[idx][v] = dist[idx][u] + 1;
                q.push(v);
            }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
        g[v - 1].push_back(u - 1);
    }
    bfs(0, 0);
    bfs(1, n - 1);
    in[0] = out[n - 1] = 1;
    calc1();
    calc2();
    for(int i = 0 ; i < n ; ++i) sz[i] = out[i] * in[i];
    cout << fixed << setprecision(12) << solve(0) << '\n';
    return 0;
}
