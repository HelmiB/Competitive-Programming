#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
vector < int > g[maxn], gr[maxn];
int path[maxn], dist[maxn];
int n, m, k;

void bfs(){
    for(int i = 0 ; i < n ; ++i) dist[i] = 1e9;
    dist[path[k - 1]] = 0;
    queue < int > q;
    q.push(path[k - 1]);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : gr[u])
            if(dist[v] > dist[u] + 1){
                dist[v] = 1 + dist[u];
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
        u--; v--;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    cin >> k;
    for(int i = 0 ; i < k ; ++i){
        cin >> path[i];
        path[i]--;
    }
    bfs();
    int mini = 0, maxi = 0;
    for(int i = 1 ; i < k ; ++i){
        int nxt = path[i];
        int u = path[i - 1];
        set < int > cnt;
        for(auto v : g[u])
            if(dist[v] + 1 == dist[u])
                cnt.insert(v);
        if(cnt.find(nxt) == cnt.end()) mini++;
        if(sz(cnt) > 1 || *cnt.begin() != nxt) maxi++;
    }
    cout << mini << ' ' << maxi << '\n';
    return 0;
}
