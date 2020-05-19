#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
vector < long long > pos;
struct node{
    long long on, off;
    int lazy;
    bool in_between;
}tree[4 * maxn];

void push(int node, int lo, int hi){
    auto &t = tree[node];
    if(!t.lazy) return;
    if(t.lazy == 1){
        t.on = pos[lo];
        t.off = -1;
        t.in_between = true; 
    }
    if(t.lazy == 2){
        t.on = -1;
        t.off = pos[lo];
        t.in_between = false; 
    }
    if(t.lazy == 3){
        swap(t.on, t.off);
        t.in_between = 1 - t.in_between;
    }
    if(lo != hi){
        auto &l = tree[2 * node + 1];
        auto &r = tree[2 * node + 2];
        if(!l.lazy) l.lazy = t.lazy;
        else if(l.lazy == 1){
            if(t.lazy != 1) l.lazy = 2;
        }else if(l.lazy == 2){
            if(t.lazy != 2) l.lazy = 1;
        }else{
            if(t.lazy == 3) l.lazy = 0;
            else l.lazy = t.lazy;
        }
        if(!r.lazy) r.lazy = t.lazy;
        else if(r.lazy == 1){
            if(t.lazy != 1) r.lazy = 2;
        }else if(r.lazy == 2){
            if(t.lazy != 2) r.lazy = 1;
        }else{
            if(t.lazy == 3) r.lazy = 0;
            else r.lazy = t.lazy;
        }
    }
    t.lazy = 0;
}

void build(int node, int lo, int hi){
    if(lo == hi){
        tree[node].on = -1;
        tree[node].off = pos[lo];
        return;
    }
    int mid = (lo + hi) >> 1;
    build(2 * node + 1, lo, mid);
    build(2 * node + 2, mid + 1, hi);
    auto &t = tree[node];
    t.on = -1;
    t.off = pos[lo];
    t.in_between = false;
}

void update(int node, int lo, int hi, int ql, int qh, int x){
    push(node, lo, hi);
    if(lo > qh || hi < ql) return;
    if(ql <= lo && hi <= qh){
        tree[node].lazy = x;
        push(node, lo, hi);
        return;
    }
    int mid = (lo + hi) >> 1;
    update(2 * node + 1, lo, mid, ql, qh, x);
    update(2 * node + 2, mid + 1, hi, ql, qh, x);
    auto &t = tree[node];
    if(ql <= mid && qh > mid){
        if(x == 1) t.in_between = true;
        if(x == 2) t.in_between = false;
        if(x == 3) t.in_between = 1 - t.in_between; 
    }
    if(~tree[2 * node + 1].on) t.on = tree[2 * node + 1].on;
    else{
        if(t.in_between && pos[mid] < pos[mid + 1] - 1) t.on = pos[mid] + 1;
        else t.on = tree[2 * node + 2].on; 
    }
    if(~tree[2 * node + 1].off) t.off = tree[2 * node + 1].off;
    else{
        if(!t.in_between && pos[mid] < pos[mid + 1] - 1) t.off = pos[mid] + 1;
        else t.off = tree[2 * node + 2].off; 
    }
}

bool v[150];
int brute(int l, int r, int x){
    for(int i = l ; i <= r ; ++i){
        if(x == 1) v[i] = true;
        if(x == 2) v[i] = false;
        if(x == 3) v[i] = 1 - v[i];
    }
    int i = 1;
    while(v[i]) ++i;
    return i;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    vector < pair < int , pair < long long, long long > > > qs;
    while(q--){
        int t;
        long long l, r;
        cin >> t >> l >> r;
        pos.push_back(l);
        pos.push_back(r);
        qs.push_back({t, {l, r}});
    }
    pos.push_back(1);
    pos.push_back(1000000000000000001);
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());
    build(0, 0, sz(pos) - 1);
    for(auto q : qs){
        int l = upper_bound(all(pos), q.second.first - 1) - pos.begin();
        int r = upper_bound(all(pos), q.second.second - 1) - pos.begin();
        assert(pos[l] == q.second.first);
        assert(pos[r] == q.second.second);
        update(0, 0, sz(pos) - 1, l, r, q.first);
        //assert(brute(pos[l], pos[r], q.first) == tree[0].off);
        cout << tree[0].off << '\n';

    }
    return 0;
}