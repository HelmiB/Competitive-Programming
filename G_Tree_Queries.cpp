#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1000500;
const int mod = 1e9 + 7;
vector < int > g[maxn];
int ans = 1e9, rt[maxn];

void init(int u, int x, int p = -1){
    x = min(x, u);
    rt[u] = x;
    for(auto v : g[u])
        if(v != p)
            init(v, x, u);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0 ; i < n - 1 ; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int r;
    cin >> r >> r;
    int rep = 0;
    r = (r + rep) % n; --q;
    init(r, r);
    ans = rt[r];
    while(q--){
        int t, u;
        cin >> t >> u;
        u = (u + rep) % n;
        if(t == 1) ans = min(ans, rt[u]);
        else{
            rep = min(ans, rt[u]) + 1;
            cout << rep << '\n';
        }
    }
    return 0;
}