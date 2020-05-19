#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1000500;
const int mod = 1e9 + 7;
int p[maxn], res[maxn];
bool vis[maxn];
vector < int > g[maxn];
vector < int > pos, num;

void solve(int u){
    if(vis[u]) return;
    vis[u] = true;
    pos.push_back(u);
    num.push_back(p[u]);
    for(auto v : g[u])
        solve(v);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) cin >> p[i];
    for(int i = 0 ; i < m ; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0 ; i < n ; ++i)
        if(!vis[i]){
            pos.clear();
            num.clear();
            solve(i);
            sort(all(pos));
            sort(all(num));
            reverse(all(num));
            for(int j = 0 ; j < sz(pos) ; ++j) res[pos[j]] = num[j];
        }
    for(int i = 0 ; i < n ; ++i) cout << res[i] << ' ';
    cout << '\n';
    return 0;
}