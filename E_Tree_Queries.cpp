#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 300500;
const int mod = 1e9 + 7;
vector < int > g[maxn]; 
int p[maxn], lvl[maxn], in[maxn], out[maxn], dep[maxn];
int cur;

void init(int u = 0, int pr = -1, int lvl = 0){
    p[u] = pr;
    dep[u] = lvl;
    in[u] = cur++;
    for(auto v : g[u])
        if(v != pr)
            init(v, u, lvl + 1);
    out[u] = cur - 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0 ; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init();
    while(q--){
        map < int, vector < int > > mp;
        int k;
        cin >> k;
        for(int i = 0 ; i < k ; ++i){
            int u;
            cin >> u;
            --u;
            mp[-dep[u]].push_back(u);
        }
        int pr = -1, prv = -1;
        bool can = true;
        for(auto d : mp){
            if(sz(d.second) == 1 && !d.second[0]) break;
            int prv = pr;
            pr = p[d.second[0]];
            for(auto u : d.second)
                if(pr != p[u]){
                    can = false;
                    break;
                }
            if(~prv && !(in[pr] <= in[prv] && in[prv] <= out[pr])) can = false;
            if(!can) break;
        }
        cout << (can ? "YES":"NO") << '\n';
    }
    return 0;
}