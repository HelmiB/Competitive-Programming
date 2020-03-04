#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
int a[maxn], b[maxn], ma[maxn], mb[maxn];

struct node{
    long long sm, mx, bst, lsm, lmx;
}tree[20 * maxn];

void push(int node, int lo, int hi){
    if(tree[node].lmx == 1e18 && !tree[node].lsm) return;
    tree[node].sm += tree[node].lsm;
    tree[node].mx = min(tree[node].mx, tree[node].lmx);
    tree[node].bst = tree[node].sm - tree[node].mx;
    if(lo != hi){
        tree[2 * node + 1].lsm += tree[node].lsm;
        tree[2 * node + 2].lsm += tree[node].lsm;
        tree[2 * node + 1].lmx = min(tree[2 * node + 1].lmx, tree[node].lmx);
        tree[2 * node + 2].lmx = min(tree[2 * node + 2].lmx, tree[node].lmx);
    }
    tree[node].lsm = 0;
    tree[node].lmx = 1e18;
}

void add(int node, int lo, int hi, int ql, int qh, long long ad, long long val){
    push(node, lo, hi);
    if(ql > hi || qh < lo) return;
    if(ql <= lo && hi <= qh){
        tree[node].lsm = ad;
        tree[node].lmx = val;
        push(node, lo, hi);
        return;
    }
    int mid = (lo + hi) >> 1;
    add(2 * node + 1, lo, mid, ql, qh, ad, val);
    add(2 * node + 2, mid + 1, hi, ql, qh, ad, val);
    if(tree[2 * node + 1].bst > tree[2 * node + 2].bst) tree[node] = tree[2 * node + 1];
    else tree[node] = tree[2 * node + 2];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    vector < pair < int, int > > as, bs;
    for(int i = 0 ; i < 20 * maxn ; ++i) tree[i].mx = tree[i].lmx = 1e18, tree[i].bst = -1e18;
    for(int i = 0 ; i < n ; ++i){
        int x, y;
        cin >> x >> y;
        as.push_back({x, y});
    }
    for(int i = 0 ; i < m ; ++i){
        int x, y;
        cin >> x >> y;
        bs.push_back({x, y});
    }
    vector < pair < pair < int, int > , int > > v;
    for(int i = 0 ; i < p ; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({{x, y}, -z});
    }
    sort(all(as));
    sort(all(bs));
    sort(all(v));
    ma[sz(as)] = mb[sz(bs)] = 1e9 + 1;
    for(int i = sz(as) - 1 ; i >= 0 ; --i){
        a[i] = as[i].first;
        ma[i] = min(ma[i + 1], as[i].second);
    }
    for(int i = sz(bs) - 1 ; i >= 0 ; --i){
        b[i] = bs[i].first;
        mb[i] = min(mb[i + 1], bs[i].second);
    }
    long long ans = - ma[0] - mb[0];
    for(int i = 0 ; i < p ; ++i){
        int ai = upper_bound(a, a + n, v[i].first.first) - a;
        int bi = upper_bound(b, b + m, v[i].first.second) - b;
        if(ai == n) break;
        if(bi == m) continue;
        add(0, 0, 1e6, v[i].first.second, 1e6, -v[i].second, 1e18);
        add(0, 0, 1e6, 0, v[i].first.second, 0, mb[bi]);
        ans = max(ans, tree[0].bst - ma[ai]);
    }
    cout << ans << '\n';
    return 0;
}
