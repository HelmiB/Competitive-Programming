#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
vector < pair < int, int > > g[maxn];
pair < pair < int, int > , pair < int, int > > ed[maxn];
bool in[maxn];
long long res[maxn];
int n, m;

struct DSU{
    private:
        int parent[maxn];
        int sz[maxn];
    public:
    int find_set(int v) {
        assert(v < maxn);
        if (v == parent[v])  return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
    }
    void init(int n){
        assert(n < maxn);
        for(int i = 0 ; i < n ; ++i)
            make_set(i);
    }
    void union_sets(int a, int b) {
        assert(a < maxn);
        assert(b < maxn);
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
}dsu;

long long krus(){
    for(int i = 0 ; i < n ; ++i) dsu.make_set(i);
    sort(ed, ed + m);
    long long ans = 0;
    for(int i = 0 ; i < m ; ++i){
        int u, v;
        tie(u, v) = ed[i].second;
        int w = ed[i].first.first;
        if(dsu.find_set(u) == dsu.find_set(v)) continue;
        in[i] = true;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        dsu.union_sets(u, v);
        ans += w;
    }
    return ans;
}

struct LCA{
    long long t[maxn],dp[maxn][35], lg[maxn], p[maxn], level[maxn], maxi[maxn][35];
    LCA(){
        lg[1] = 0 ;
        for(int i = 2 ; i < maxn; ++i)
            lg[i] = 1 + lg[i/2];
    }
    void init(int u, int par = -1, int lev = 0, int w = 0){
        p[u] = par ;
        level[u] = lev;
        maxi[u][0] = w;
        for(auto v : g[u])
            if(v.first != par)
               init(v.first , u, lev + 1, v.second);
    }
    void build(int n){
        assert(n < maxn);
        for(int i = 0 ; i < n ; ++i)
            if(!level[i])
                init(i);
        int L = lg[n];
        for(int j = 1; (1 << j) < n; j++)
            for(int i = 0 ; i < n ; i++)
                dp[i][j] = -1;
        for(int i = 0 ; i < n ; i++) 
            dp[i][0] = p[i];
        for(int j = 1 ; (1 << j) < n ; j++)
            for(int i = 0 ; i < n ; i++) 
                if(dp[i][j - 1] != -1)
                    dp[i][j] = dp[dp[i][j - 1]][j - 1], maxi[i][j] = max(maxi[i][j - 1], maxi[dp[i][j - 1]][j - 1]);
    }
    long long lca(int u , int v){
        assert(u >= 0 && v >= 0 && u < maxn && v < maxn);
        long long ans = 0;
        if(level[u] < level[v]) swap(u,v);
        int L = lg[level[u]];
        for(int j = L ; j >= 0 ; j--)
            if(level[u] - (1 << j) >= level[v])
                ans = max(ans, maxi[u][j]), u = dp[u][j];     
        if(u == v) return ans ;
        for(int j = L;j >= 0; j--)
            if(dp[u][j] != -1 && dp[u][j] != dp[v][j]){
                ans = max(ans, maxi[u][j]);
                ans = max(ans, maxi[v][j]);
                u= dp[u][j];
                v= dp[v][j];
            }
        ans = max(ans, maxi[u][0]);
        ans = max(ans, maxi[v][0]);
        return ans;
    }
}lc;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    ;
    for(int i = 0 ; i < m ; ++i){
        cin >> ed[i].second.first >> ed[i].second.second >> ed[i].first.first;
        ed[i].second.first--;
        ed[i].second.second--;
        ed[i].first.second = i;
    }
    long long ans = krus();
    lc.build(n);
    for(int i = 0 ; i < m ; ++i)
        if(in[i]) res[ed[i].first.second] = ans;
        else {
            int u, v;
            tie(u, v) = ed[i].second;
            int w = ed[i].first.first;
            res[ed[i].first.second] = ans - lc.lca(u, v) + w;
        }
    for(int i = 0 ; i < m ; ++i) cout << res[i] << '\n';
    return 0;
}
