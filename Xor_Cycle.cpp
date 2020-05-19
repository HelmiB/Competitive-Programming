#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
vector < pair < int, int > > g[maxn];
int best[100], xr[maxn];
bool vis[maxn];

struct Gaussian_Elimination{
    int best[65], added[65];
    void add(int x, int t_add = 0){
        for(int i = 60 ; i >= 0 ; --i)
            if((1ll << i) & x){
            if(!best[i]){
                best[i] = x ;
                added[i] = t_add;
                return;
            }
            if(added[i] < t_add){
                swap(best[i], x);
                swap(added[i], t_add);
            }
            x ^= best[i];
        }
    }
    int query(int t_add = 0){
        int ans = 0;
        for(int i = 60 ; i >= 0 ; --i)
            if(added[i] >= t_add && ans < (ans ^ best[i]))
                ans ^= best[i];
        return ans;
    }
}gauss;



void init(int u = 0, int p = -1, int e = 0){
    if(~p) xr[u] = xr[p] ^ e;
    vis[u] = true;
    for(auto v : g[u])
        if(!vis[v.first]){
            init(v.first, u, v.second);
        }else if(v.first != p){
            gauss.add(xr[u] ^ xr[v.first] ^ v.second);
        }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    init();
    cout << gauss.query() << '\n';
    return 0;
}