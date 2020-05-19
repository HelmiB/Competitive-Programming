#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const ll MOD=1e9 + 7 ;
const ll dx[4] = { -1,1,0,0 };
const ll dy[4] = { 0,0,-1,1 };
const ll MAX =  3e5 + 5 ;
#define pb push_back
#define f first
#define s second
#define all(v) v.begin(),v.end()
long long gcd(long long  a, long long  b) { return (b == 0 ? a : gcd(b, a % b)); }
ll n , m  , k , Q , x , y, ans;
ll id[MAX],low[MAX],cc[MAX],lg[MAX],dist[MAX];
bool vis[MAX];
vector < vector < pair  < int , int >  > > g ;
struct edge{
    int u, v, w;
}ed[MAX];
vector < vector < pair < int, int > > > gtree;
int cur = 0 ;
queue < ll > q ;
vector < int > res ;
bool done[MAX],is_bridge[MAX];
void solve(int u , int parent = -1)
{

    vis[u] = true ;
    low[u] = id[u] = cur++;
    for(auto &v : g[u])
    {
        if(v.f == parent && done[v.s]) continue ; // done is made for multiple edges
        done[v.s] = true ;
        if(!vis[v.f])
            {
                solve(v.f,u);
                low[u] = min(low[u],low[v.f]);
                if(id[u] < low[v.f])
                    {

                        is_bridge[v.s] = true ;
                        res.pb(v.second);

                    }

            }
        else
            low[u] = min(low[u],id[v.f]);

    }

}

void dfs(int u )
{

    if(vis[u]) return ;
    cc[u] = cur ;
    vis[u] = true ;
    for(auto v : g[u])
        if(!vis[v.f])
        {

            if(is_bridge[v.s])
                q.push(v.f);
            else
                dfs(v.f);
        }

}
int at = -1 ;
int mx ;
int lv[MAX], pr[MAX], wp[MAX];
bool good[MAX];
void dfstree(int node ,int p = -1 ,int len = 0 ){
    lv[node] = len;
    pr[node] = p; 
    for (auto child : gtree[node])
        if (child.first!=p)
            dfstree(child.first,node,len+1), wp[child.first] = child.second;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    g.clear();
    g.resize(MAX);
    gtree.clear();
    gtree.resize(MAX);
    cin>>n>>m;
    for(int i = 0 ; i < m ; ++i){
            int u , v, w;
            cin>>u>>v>>w;
            --u; --v;
            ed[i].u = u;
            ed[i].v = v;
            ed[i].w = w;
            g[u].pb({v,i});
            g[v].pb({u,i});
        }
    for(int i = 0 ; i < n ; ++i) sort(all(g[i]));
    for(int i = 0 ; i < n ; ++i)
        if(!vis[i])
            solve(i);
    q.push(0);
    cur = 0 ;
   for(int i = 0 ; i <= n ; ++i) vis[i] = false ;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        if(vis[u]) continue ;
        ++cur;
        dfs(u);
    }
    for(int i = 0 ; i < res.size() ; ++i){
            gtree[cc[ed[res[i]].u]].pb({cc[ed[res[i]].v], ed[res[i]].w});
            gtree[cc[ed[res[i]].v]].pb({cc[ed[res[i]].u], ed[res[i]].w});
        }
    for(int i = 0 ; i < m ; ++i)
        if(cc[ed[i].u] == cc[ed[i].v] && ed[i].w)
            good[cc[ed[i].u]] = true;
    dfstree(1);
    int a, b;
    cin >> a >> b;
    --a; --b;
    a = cc[a];
    b = cc[b];
    if(lv[a] > lv[b]) swap(a, b);
    bool can = false;
    while(lv[b] > lv[a]){
        can |= good[b];
        can |= (wp[b]);
        b = pr[b];
    }
    while(a != b){
        can |= (good[b] | good[a]);
        can |= (wp[a]);
        a = pr[a];
        can |= (wp[b]);
        b = pr[b];
    }
    can |= (good[b] | good[a]);
    cout << (can ? "YES\n":"NO\n");
    return 0;
}