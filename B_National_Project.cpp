#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
vector < int > x[maxn];
vector < int > tree[maxn];
int ans[maxn];
vector < pair < pair < int, int >, pair < int, int > > > pending;

struct node{
    int tm, id;
    int st;
}tc[4 * maxn];

void update_tc(int node, int lo, int hi, int ql, int qh, int t, int id){
    if(ql > hi || qh < lo) return;
    if(ql <= lo && hi <= qh){
        tc[node].tm = t;
        tc[node].id = id;
        tc[node].st = lo - ql;
        //cout << lo << ' ' << hi << ' ' << ql << ' ' << qh << '\n';
        return;
    }
    int mid = (lo + hi) >> 1;
    update_tc(2 * node + 1, lo, mid, ql, qh, t, id);
    update_tc(2 * node + 2, mid + 1, hi, ql, qh, t, id);
}

void query_tc(int node, int lo, int hi, int p, int &t, int &idx, int &pos){
    if(tc[node].tm >= t){
        t = tc[node].tm;
        idx = tc[node].id;
        pos = tc[node].st + p - lo;
        //cout << lo << ' ' << hi << ' ' << idx << ' ' << tc[node].st << '\n';
    }
    if(lo == hi) return;
    int mid = (lo + hi) >> 1;
    if(p <= mid) query_tc(2 * node + 1, lo, mid, p, t, idx, pos);
    else query_tc(2 * node + 2, mid + 1, hi, p, t, idx, pos);
}

void build(int id, int node, int lo, int hi){
    if(lo == hi){
        tree[id][node] = x[id][lo];
        return;
    }
    int mid = (lo + hi) >> 1;
    build(id, 2 * node + 1, lo, mid);
    build(id, 2 * node + 2, mid + 1, hi);
}

void update(int id, int node, int lo, int hi, int ql, int qh){
    if(ql > hi || qh < lo) return;    
    if(ql <= lo && hi <=  qh){
        tree[id][node]++;
        return;
    }
    int mid = (lo + hi) >> 1;
    update(id, 2 * node + 1, lo, mid, ql, qh);
    update(id, 2 * node + 2, mid + 1, hi, ql, qh);
}

void query(int id, int node, int lo, int hi, int p, int &ans){
    ans += tree[id][node];
    ans %= 256;
    if(lo == hi) return;
    int mid = (lo + hi) >> 1;
    if(p <= mid) query(id, 2 * node + 1, lo, mid, p, ans);
    else query(id, 2 * node + 2, mid + 1, hi, p, ans);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1 ; i <= m ; ++i){
        int k;
        cin >> k;
        for(int j = 0 ; j < k ; ++j){
            int xi;
            cin >> xi;
            x[i].push_back(xi);
        }
        tree[i].resize(4 * k);
        build(i, 0, 0, k - 1);
    }
    priority_queue < pair < pair < int, int >, pair < int, int > > > pq;
    int len = 0;
    for(int i = 1 ; i <= q ; ++i){
        ans[i] = -1;
        int t;
        cin >> t;
        if(t == 1){
            int id, p;
            cin >> id >> p;
            update_tc(0, 0, n - 1, p - 1, p + sz(x[id]) - 2, i, id);
        }
        if(t == 2){
            int p;
            cin >> p;
            int ps = -1, id = -1, tm = -1;
            query_tc(0, 0, n - 1, p - 1, tm, id, ps);
            if(!id) ans[i] = 0;
            else{
                assert(~ps);
                pq.push({{-tm , i} , {id, ps}});
            }
        }
        if(t == 3){
            int id, l, r;
            cin >> id >> l >> r;
            --l; --r;
            pending.push_back({{i, id}, {l, r}});
        }
    }
    for(int i = 0 ; i < sz(pending) ; ++i){
        auto u = pending[i];
        while(!pq.empty() && -pq.top().first.first < u.first.first){
            auto v = pq.top();
            pq.pop();
            ans[v.first.second] = 0;
            query(v.second.first, 0, 0, sz(x[v.second.first]) - 1, v.second.second, ans[v.first.second]);
        }
        update(u.first.second, 0, 0, sz(x[u.first.second]) - 1, u.second.first, u.second.second);
    }
    while(!pq.empty()){
        auto v = pq.top();
        pq.pop();
        ans[v.first.second] = 0;
        query(v.second.first, 0, 0, sz(x[v.second.first]) - 1, v.second.second, ans[v.first.second]);
    }
    for(int i = 1 ; i <= q ; ++i)
        if(~ans[i])
            cout << ans[i] << '\n';
    return 0;
}