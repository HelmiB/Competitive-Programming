#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
int d[3][maxn];
vector < int > g[maxn];
int n, m;

void bfs(int idx, int st){
    for(int i = 0 ; i < n ; ++i) d[idx][i] = 1e18;
    d[idx][st] = 0;
    queue < int > q;
    q.push(st);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v : g[u])
            if(d[idx][v] == 1e18){
                d[idx][v] = d[idx][u] + 1;
                q.push(v);
            }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> n >> m >> a >> b >> c;
        --a; --b; --c;
        for(int i = 0 ; i < n ; ++i) g[i].clear();
        vector < int > p(m);
        for(auto &x : p) cin >> x;
        sort(all(p));
        for(int i = 1 ; i < m ; ++i) p[i] += p[i - 1];
        for(int i = 0 ; i < m ; ++i){
            int u, v;
            cin >> u >> v;
            --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bfs(0, b);
        bfs(1, a);
        bfs(2, c);
        int ans = 1e18;
        for(int i = 0 ; i < n ; ++i){
            int b = d[0][i];
            int a = d[1][i];
            int c = d[2][i];
            if(a + b + c <= m) ans = min(ans, (b ? 2 * p[b - 1]:0) +
             (a + b + c ? p[a + b + c - 1] - (b ? p[b - 1]:0):0));
        }
        cout << ans << '\n';
    }   

    return 0;
}