#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

struct flow_graph{
    int MAX_V,E,s,t,head,tail;
    int *to,*next,*cap,*last,*dist,*q,*now;
    flow_graph(){}
    void clear(){
        fill(last,last+MAX_V,-1);
        E=0;
    }
    flow_graph(int V,int MAX_E){
        MAX_V=V;
        to=new int[2*MAX_E],cap=new int[2*MAX_E],next=new int[2*MAX_E];
        dist=new int[MAX_V],last=new int[MAX_V],q=new int[MAX_V],now=new int[MAX_V];
        clear();
    }
    void add_edge(int u,int v,int uv,int vu=0){
        to[E]=v,next[E]=last[u],last[u]=E,cap[E]=uv,E++;
        to[E]=u,next[E]=last[v],last[v]=E,cap[E]=vu,E++;
    }
    bool bfs(){
        fill(dist,dist+MAX_V,-1);
        head=tail=0;
        q[tail]=t;
        dist[t]=0;
        tail++;
        while(head<tail){
            int u=q[head++];
            for(int e=last[u];e!=-1;e=next[e]){
                int v=to[e];
                if(cap[e^1]>0 && dist[v]==-1)
                    q[tail++]=v,dist[v]=dist[u]+1;
            }
        }
        return dist[s]!=-1;
    }
    int dfs(int u,int f){
        if(u==t)return f;
        for(int &e=now[u];e!=-1;e=next[e]){
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
            for(int i=0;i<MAX_V;i++)now[i]=last[i];
            while(true){
                df=dfs(s,1<<15);
                if(df==0)break;
                f+=df;
                
            }
        }
        return f;
    }
};

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector < int > a(n + 1);
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    int ans = 0;
    for(auto x : a) ans += max(0LL, x);
    flow_graph fw(n + 3, n * n);
    for(int i = 1 ; i <= n ; ++i){
        if(a[i] < 0) fw.add_edge(0, i, -a[i]);
        else fw.add_edge(i, n + 1, a[i]);
        for(int j = i + i; j <= n ; j += i)
            fw.add_edge(i, j, 1e18);
    }
    cout << ans - fw.dinic(0, n + 1) << '\n';
    return 0;
}