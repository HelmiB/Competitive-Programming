#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int cnt[2 * maxn];
long long L[2 * maxn];
pair < pair < int , int > , int > a[2 * maxn];
long long tree[4 * maxn];

void build(int node, int lo, int hi){
    if(lo == hi){
        tree[node] = a[lo].first.first + a[lo].first.second;
        return;
    }
    int mid = (lo + hi) >> 1;
    build(2 * node + 1, lo , mid);
    build(2 * node + 2, mid + 1, hi);
    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
}

long long query(int node, int lo, int hi, int ql, int qh){
    if(ql > qh || lo > qh || hi < ql) return -1;
    if(ql <= lo && hi <= qh) return tree[node];
    int mid = (lo + hi) >> 1;
    return max(query(2 * node + 1, lo , mid , ql, qh), query(2 * node + 2, mid + 1, hi, ql, qh));
}

void update(int node, int lo, int hi, int el, long long len){
    if(lo == hi){
        tree[node] += len;
        cnt[a[lo].second]++;
        L[a[lo].second] += len;
        return;
    }
    int mid = (lo + hi) >> 1;
    if(el <= mid) update(2 * node + 1, lo, mid, el, len);
    else update(2 * node + 2, mid + 1, hi, el, len);
    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) cin >> a[i].first.first >> a[i].first.second, a[i].second = i, L[i] = a[i].first.second;
    sort(a, a + n);
    build(0, 0, n - 1);
    set < pair < int , pair < int, int > > > msq;
    for(int i = 0 ; i < m ; ++i){
        int p, b;
        cin >> p >> b;
        int lo = 0, hi = n - 1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(a[mid].first.first <= p) lo = mid + 1;
            else hi = mid - 1;
        }
        if(!lo) continue;
        int R = lo - 1;
        lo = 0, hi = R;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(query(0, 0, n - 1, 0, mid) >= p) hi = mid - 1;
            else lo = mid + 1;
        }
        if(hi == R){
            msq.insert({p, {b, i}});
            continue;
        }
        update(0, 0, n - 1, hi + 1, b);
        while(1){
            if(msq.upper_bound(make_pair(a[hi + 1].first.first, make_pair(-1, -1))) == msq.end()) break;
            auto v = *msq.upper_bound(make_pair(a[hi + 1].first.first, make_pair(-1, -1)));
            if(v.first > a[hi + 1].first.first + L[a[hi + 1].second]) break;
            msq.erase(v);
            update(0, 0, n - 1, hi + 1, v.second.first);
        }
    }
    for(int i = 0 ; i < n ; ++i) cout << cnt[i] << ' ' << L[i] << '\n';
    return 0;
}
