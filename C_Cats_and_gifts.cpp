#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int lazy[4 * maxn], tree[4 * maxn], x[maxn], v[maxn], e[maxn];

void push(int node, int lo, int hi){
    if(!lazy[node]) return;
    tree[node] += lazy[node];
    if(lo != hi){
        lazy[2 * node + 1] += lazy[node];
        lazy[2 * node + 2] += lazy[node];
    }
    lazy[node] = 0;
}
void update(int node, int lo, int hi, int ql, int qh, int x){
    push(node, lo, hi);
    if(ql > hi || qh < lo || lo > hi) return;
    if(ql <= lo && hi <= qh){
        lazy[node] = x;
        push(node, lo, hi);
        return ;
    }
    int mid = (lo + hi) >> 1;
    update(2 * node + 1, lo, mid, ql, qh, x);
    update(2 * node + 2, mid + 1, hi, ql, qh, x);
    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
}

int query(int node, int lo, int hi, int ql, int qh){
    push(node, lo, hi);
    if(ql > hi || qh < lo) return -1;
    if(ql <= lo && hi <= qh) return tree[node];
    int mid = (lo + hi) >> 1;
    int ans = max(query(2 * node + 1, lo, mid, ql, qh), query(2 * node + 2, mid + 1, hi, ql, qh));
    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> x[i] >> v[i] >> e[i];
    int ans = 0;
    x[n] = x[n - 1];
    for(int i = n - 2 ; i >= 0 ; --i) v[i] += v[i + 1];
    for(int i = n - 1 ; i >= 0 ; --i){
        update(0, 0, n - 1, i + 1, n - 1, e[i] - (x[i + 1] - x[i]));
        update(0, 0, n - 1, i, i, e[i]);
        int lo = i, hi = n - 1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(query(0, 0, n - 1, mid, n - 1) >= 0) lo = mid + 1;
            else hi = mid - 1;
        }
        ans = max(ans, v[i] - v[lo]);
    }
    cout << ans << '\n';
    return 0;
}