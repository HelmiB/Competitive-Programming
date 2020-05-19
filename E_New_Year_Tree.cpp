#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 400500;
const int mod = 1e9 + 7;
bitset < 61 > tree[4 * maxn];
bitset < 61 > lazy[4 * maxn];
short c[maxn], col[maxn];
int in[maxn], out[maxn];
vector < int > g[maxn];
int cur;

void dfs(int u = 0, int p = -1){
    in[u] = cur++;
    col[cur - 1] = c[u];
    for(auto v : g[u])
        if(v != p)
            dfs(v, u);
    out[u] = cur - 1;    
}

void pull(int node){
    tree[node] = (tree[2 * node + 1] | tree[2 * node + 2]);
}

void build(int node, int lo, int hi){
    if(lo == hi){
        tree[node].set(col[lo]);
        return ;
    }
    int mid = (lo + hi) >> 1;
    build(2 * node + 1, lo, mid);
    build(2 * node + 2, mid + 1, hi);
    pull(node);
}

void push(int node, int lo, int hi){
    if(!lazy[node].count()) return;
    int pos = lazy[node]._Find_first();
    tree[node].reset();
    tree[node].set(pos);
    lazy[node].reset();
    if(lo == hi) return;
    lazy[2 * node + 1].reset();
    lazy[2 * node + 2].reset();
    lazy[2 * node + 1].set(pos);
    lazy[2 * node + 2].set(pos);
}

void update(int node, int lo, int hi, int ql, int qh, int pos){
    push(node, lo, hi);
    if(lo > hi || lo > qh || hi < ql) return;
    if(ql <= lo && hi <= qh){
        lazy[node].set(pos);
        push(node, lo, hi);
        return;
    }
    int mid = (lo + hi) >> 1;
    update(2 * node + 1, lo , mid, ql, qh, pos);
    update(2 * node + 2, mid + 1, hi, ql, qh, pos);
    pull(node);
}

bitset < 61 > nl;
bitset < 61 > query(int node, int lo, int hi, int ql, int qh){
    push(node, lo, hi);
    if(!tree[node].count()) return nl;
    if(lo > hi || lo > qh || hi < ql) return nl;
    if(ql <= lo && hi <= qh) return tree[node];
    int mid = (lo + hi) >> 1;
    bitset < 61 > res = (query(2 * node + 1, lo, mid, ql, qh) | query(2 * node + 2, mid + 1, hi, ql, qh));
    pull(node);
    return res;
}

inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
 
template<typename T = int>
inline T readNxt(){
    char c=nc();T x=0; int f=1;
    for(;c>'9'||c<'0';c=nc())if(c=='-')f=-1;
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc()); x*=f;
    return x;
}
 

int main(){
    int n, m;
    n = readNxt(), m = readNxt();
    for(int i = 0 ; i < n ; ++i) c[i] = readNxt();
    for(int i = 0 ; i < n - 1 ; ++i){
        int u = readNxt();
        int v = readNxt();
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs();
    build(0, 0, n - 1);
    vector < int > rs;
    while(m--){
        int t, u, c;
        t = readNxt();
        u = readNxt();
        --u;
        if(t == 1){
            c = readNxt();
            update(0, 0, n - 1, in[u], out[u], c);
        }else printf("%d\n", query(0, 0, n - 1, in[u], out[u]).count());
    }   
    return 0;
}
