#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1000500;
const int mod = 1e9 + 7;
int tree[4 * maxn];
struct Point{
    int x, y;
};

struct Segment{
    Point l, r;
}seg[maxn];


struct SparseTable{
    long long t[maxn],dp[maxn][21], lg[maxn];
    SparseTable(){
        lg[1] = 0 ;
        for(int i = 2 ; i < maxn; ++i)
            lg[i] = 1 + lg[i/2];
    }
    void build(int n){
        assert(n < maxn);
        memset(dp, -1, sizeof dp);
        for(int i = 0 ; i < n ; ++i)
            dp[i][0] = t[i];
        for(int j = 1 ; j <= 20 ; ++j)
            for(int i = 0 ; i < n ; ++i)
                if(~dp[i][j - 1] && dp[i][j - 1] != i){
                    if(dp[dp[i][j - 1]][j - 1] != dp[i][j - 1])
                    dp[i][j] = dp[dp[i][j - 1]][j - 1]; 
                }
    }
}spt;

void update(int node, int lo, int hi, int ql, int qh, int id){
    if(ql > hi || qh < lo) return ;
    if(ql <= lo && hi <= qh){
        tree[node] = id;
        return;
    }
    int mid = (lo + hi) >> 1;
    update(2 * node + 1, lo, mid, ql, qh, id);
    update(2 * node + 2, mid + 1, hi, ql, qh, id);
}

void get(int node, int lo, int hi, int el, int &id){
    if(el < lo || el > hi) return;
    id = max(id, tree[node]);
    if(lo == hi) return;
    int mid = (lo + hi) >> 1;
    if(el <= mid) get(2 * node + 1, lo, mid, el, id);
    else get(2 * node + 2, mid + 1, hi, el, id);
}

inline bool cmp(const Segment &a, const Segment &b){
    if(a.r.y != b.r.y)
        return a.r.y > b.r.y;
    return a.l.x < b.l.x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0 ; i < n ; ++i){
        cin >> seg[i].l.x >> seg[i].l.y >> seg[i].r.x >> seg[i].r.y;
        if(seg[i].l.y > seg[i].r.y) swap(seg[i].l, seg[i].r);
    }
    
    sort(seg, seg + n, cmp);    
    for(int i = 0 ; i < n ; ++i){
        int x = (seg[i].l.y > seg[i].r.y ? seg[i].l.x:seg[i].r.x);
        if(seg[i].l.y != seg[i].r.y){
            int p = -1;
            get(0, 0, maxn - 1, x, p);
            if(p <= 0) p = i;
            else p--;
            spt.t[i] = p;
        }else{
            spt.t[i] = i;
        }
        update(0, 0, maxn - 1, min(seg[i].l.x, seg[i].r.x), max(seg[i].l.x, seg[i].r.x), i + 1);
    }
    spt.build(n);
    while(q--){
        int x;
        cin >> x;
        int p = -1;
        get(0, 0, maxn - 1, x, p);
        if(p <= 0){
            cout << x << '\n';
            continue;
        }
        p--;
        if(spt.dp[p][0] == p){
            if(seg[p].l.y != seg[p].r.y){
                cout << (seg[p].l.y > seg[p].r.y ? seg[p].l.x:seg[p].r.x) << '\n';
            }else{
                cout << (seg[p].l.y > seg[p].r.y ? seg[p].l.x:seg[p].r.x) << ' ' << seg[p].l.y << '\n';
            }
            continue;
        }
        int prv = -1;
        while(1){
            int pr = -1;
            bool flag = false;
            for(int j = 20 ; j >= 0 ; --j)
                if(~spt.dp[p][j]){
                    pr = spt.dp[p][j];
                    if(pr == p) break;
                    if(!j){
                        prv = p;
                        p = pr;
                        break;
                    }
                    flag = true;
                    prv = spt.dp[p][j - 1];
                    p = pr;
                    break;
                }
            if(!flag) break;
        }
        /*cout << p << " = " << seg[p].l.x << ' ' << seg[p].l.y << ' ' << seg[p].r.x << ' ' << seg[p].r.y << '\n';
        cout << prv << '\n';*/
        if(seg[p].l.y != seg[p].r.y){
            cout << (seg[p].l.y > seg[p].r.y ? seg[p].l.x:seg[p].r.x) << '\n';
        }else{
            cout << (seg[prv].l.y > seg[prv].r.y ? seg[prv].l.x:seg[prv].r.x) 
            << ' ' << seg[p].l.y << '\n';
        }
    }
    return 0;
}