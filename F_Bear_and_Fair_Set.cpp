#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

int get(int L, int R, int md){
    int lo = (L % 5 == 0 ? L:L + 5 - L%5), hi = (R % 5 == 0 ? R : R - R%5);
    int d = hi / 5 - max(0, (lo - 1)) / 5;
    if(R - hi < md) d--;
    if(lo - L >= 5 - md) d++;
    return d;
}


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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, b, q;
    cin >> n >> b >> q;
    vector < pair < int, int > > qs;
    while(q--){
        int R, Q;
        cin >> R >> Q;
        qs.push_back({R, Q});
    }
    sort(all(qs));
    qs.push_back({b, n});
    flow_graph F(sz(qs) + 7, 7e4);
    int prv = 1, vpr = 0;
    for(int i = 0 ; i < sz(qs) ; ++i){
        if(i < sz(qs) - 1 && ((qs[i + 1].second - qs[i].second > qs[i + 1].first - qs[i].first) || qs[i].second > qs[i + 1].second))
            return cout << "unfair\n\n", 0;
        for(int j = 0 ; j < 5 ; ++j){
            int ad = get(prv, qs[i].first, j);
            if(ad) F.add_edge(sz(qs) + j + 1, i + 1, ad);
        }
        F.add_edge(i + 1, sz(qs) + 6, qs[i].second - vpr);
        prv = qs[i].first + 1;
        vpr = qs[i].second;
    }
    for(int i = sz(qs) + 1; i <= sz(qs) + 5 ; ++i)
        F.add_edge(0, i, n / 5);
    cout << (F.dinic(0, sz(qs) + 6) == n ? "fair\n":"unfair\n");
    return 0;
}
