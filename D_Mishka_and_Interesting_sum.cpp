#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1000010;
const int mod = 1e9 + 7;
int a[maxn], ans[maxn], tree[4 * maxn], nx[maxn], pref[maxn];
vector < pair < int, int > > q[maxn];
 
int query(int node, int lo, int hi, int ql, int qh){
    if(lo > qh || hi < ql) return 0;
    if(ql <= lo && hi <= qh) return tree[node];
    int mid = (lo + hi) >> 1;
    return (query(2 * node + 1, lo, mid, ql, qh) ^ query(2 * node + 2, mid + 1, hi, ql, qh));
}
 
void update(int node, int lo, int hi, int el, int val){
    if(lo == hi){
        assert(lo == el);
        tree[node] ^= val;
        return; 
    }
    int mid = (lo + hi) >> 1;
    if(el <= mid) update(2 * node + 1, lo, mid, el, val);
    else update(2 * node + 2, mid + 1, hi, el, val);
    tree[node] = (tree[2 * node + 1] ^ tree[2 * node + 2]);
}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    map < int, int > nxt;
    for(int i = 0 ; i < n ; ++i) cin >> a[i], nxt[a[i]] = n;
    for(int i = n - 1 ; i >= 0 ; --i){
        nx[i] = nxt[a[i]];
        nxt[a[i]] = i;
    }
    pref[0] = a[0];
    for(int i = 1 ; i < n ; ++i) pref[i] = pref[i - 1] ^ a[i];
    cin >> m;
    for(int i = 0 ; i < m ; ++i){
        int l, r;
        cin >> l >> r;
        --l; --r;
        if(l > 0) q[l - 1].push_back({r, i});
        q[r].push_back({r, i});
        ans[i] = (pref[r] ^ (l > 0 ? pref[l - 1]:0));
    }
    for(int i = 0 ; i < n ; ++i){
        update(0, 0, n, nx[i], a[i]);
        for(auto u : q[i]) ans[u.second] ^= query(0, 0, n, u.first + 1, n);
    }
    for(int i = 0 ; i < m ; ++i) cout << ans[i] << '\n';
    return 0;
}
