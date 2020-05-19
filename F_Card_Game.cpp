#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 205;
const int mod = 1e9 + 7;
bool pr[200500];

void build(){
    memset(pr, true, sizeof pr);
    pr[0] = pr[1] = false;
    for(int i = 2 ; i < 200500 ; ++i)
        if(pr[i])
            for(int j = i + i ; j < 200500; j += i)
                pr[j] = false;
}

int MAX_V,E,s,t,head,tail;
int to[2 * maxn * maxn], cap[2 * maxn * maxn], nxt[2 * maxn * maxn];
int dist[maxn], lst[maxn], q[maxn], now[maxn];
struct flow_graph{
    flow_graph(){}
    void clear(){
        fill(lst,lst+MAX_V,-1);
        E=0;
    }
    flow_graph(int V){
        MAX_V=V;
        clear();
    }
    void add_edge(int u,int v,int uv,int vu=0){
        to[E]=v,nxt[E]=lst[u],lst[u]=E,cap[E]=uv,E++;
        to[E]=u,nxt[E]=lst[v],lst[v]=E,cap[E]=vu,E++;
    }
    bool bfs(){
        fill(dist,dist+MAX_V,-1);
        head=tail=0;
        q[tail]=t;
        dist[t]=0;
        tail++;
        while(head<tail){
            int u=q[head++];
            for(int e=lst[u];e!=-1;e=nxt[e]){
                int v=to[e];
                if(cap[e^1]>0 && dist[v]==-1)
                    q[tail++]=v,dist[v]=dist[u]+1;
            }
        }
        return dist[s]!=-1;
    }
    int dfs(int u,int f){
        if(u==t)return f;
        for(int &e=now[u];e!=-1;e=nxt[e]){
            int v=to[e];
            if(cap[e]>0 && dist[v]==dist[u]-1){
                int df=dfs(v,min(f,cap[e]));
                if(df>0){
                    cap[e]-=df;
                    cap[e^1]+=df;
                    return df;
                }
            }
        }
        return 0;
    }
    int dinic(int src,int snk){
        s=src,t=snk;
        int f=0,df;
        while(bfs()){
            for(int i=0;i<MAX_V;i++)now[i]=lst[i];
            while(true){
                df=dfs(s,1<<15);
                if(df==0)break;
                f+=df;
                
            }
        }
        return f;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    build();
    vector < pair < int, pair < int, int > > > v;
    vector < pair < int, int > > one;
    for(int i = 0 ; i < n ; ++i){
        int p, c, l;
        cin >> p >> c >> l;
        if(c == 1) one.push_back({l, p});
        else v.push_back({l, {p, c}});
    }
    sort(all(one));
    sort(all(v));
    int lo = 1, hi = n;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        int maxi = -1;
        for(int i = 0 ; i < sz(one) && one[i].first <= mid ; ++i)
            maxi = max(maxi, one[i].second);
        vector < pair < int, int > > id;
        long long sm = 0;
        if(~maxi) id.push_back({1, maxi}), sm = maxi;
        for(int i = 0 ; i < sz(v) && v[i].first <= mid ; ++i) 
            id.push_back({v[i].second.second, v[i].second.first}), sm += v[i].second.first;
        flow_graph g(sz(id) + 2);
        for(int i = 0 ; i < sz(id) ; ++i)
            if((id[i].first % 2) == 0)
                for(int j = 0 ; j < sz(id) ; ++j)
                    if(pr[id[i].first + id[j].first])
                        g.add_edge(i, j, 1e9);
        for(int i = 0 ; i < sz(id) ; ++i)
            if(id[i].first & 1){
                g.add_edge(i, sz(id) + 1, id[i].second);
            }else{
                g.add_edge(sz(id), i, id[i].second);
            }
        if(sm - g.dinic(sz(id), sz(id) + 1) >= k) hi = mid - 1;
        else lo = mid + 1;   
    }
    if(hi == n) return cout << -1 << '\n', 0;
    cout << hi + 1 << '\n';
    return 0;
}