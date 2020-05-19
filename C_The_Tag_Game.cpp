#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
vector < int > g[maxn];
int dep[maxn], len[maxn], par[maxn];

void init(int u = 0, int p = -1){
    dep[u] = (~p ? 1 + dep[p]:0);
    par[u] = p;
    for(auto v : g[u])
        if(v != p){
            init(v, u);
            len[u] = max(len[u], 1 + len[v]);
        }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    --x;
    for(int i = 0 ; i < n - 1 ; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init();
    int ans = 0, d = 0;
    while(~x && d < dep[x]){
        ans = max(ans, len[x] + dep[x]);
        d++;
        x = par[x];
    }
    cout << 2 * ans << '\n';
    return 0;
}