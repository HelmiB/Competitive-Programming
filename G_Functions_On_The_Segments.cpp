#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9;
struct node{
    long long x1, x2, y1, a, b, y2;
}arr[maxn];
long long pa[maxn], pb[maxn];

struct MergeSortTree{
    private:
    vector < pair < int, int > > tree[4 * maxn];
    vector < long long > as[4 * maxn], bs[4 * maxn], ys[4 * maxn];
    int a[4 * maxn];
    public:
    long long op(long long a, long long b){
        // change operation here
        return a + b;
    }
    void build(int node, int lo, int hi){
    if(lo == hi){
        tree[node].push_back({arr[lo].x1, lo});
        as[node].push_back(arr[lo].a);
        bs[node].push_back(arr[lo].b);
        ys[node].push_back(arr[lo].y1);
        return;
    }
    int mid = (lo + hi) >> 1;
    build(2 * node + 1, lo, mid);
    build(2 * node + 2, mid + 1, hi);
    merge(tree[2 * node + 1].begin(), tree[2 * node + 1].end(), tree[2 * node + 2].begin(), tree[2 * node + 2].end(),
            back_inserter(tree[node]));
    as[node].push_back(arr[tree[node][0].second].a);
    for(int i = 1 ; i < (int)tree[node].size(); ++i)
        as[node].push_back(op(as[node][i - 1], arr[tree[node][i].second].a));
    bs[node].push_back(arr[tree[node][0].second].b);
    for(int i = 1 ; i < (int)tree[node].size(); ++i)
        bs[node].push_back(op(bs[node][i - 1], arr[tree[node][i].second].b));
    ys[node].push_back(arr[tree[node][0].second].y1);
    for(int i = 1 ; i < (int)tree[node].size(); ++i)
        ys[node].push_back(op(ys[node][i - 1], arr[tree[node][i].second].y1));
    }
    
    long long query(int node, int lo, int hi, int ql, int qh, int X){
        if(lo > hi || ql > hi || qh < lo) return 0;
        if(ql <= lo && hi <= qh){
            long long ans = 0;
            int idx = upper_bound(all(tree[node]), make_pair(X - 1, maxn)) - tree[node].begin() - 1;
            long long rema = 0, remb = 0, remy = 0;
            if(idx >= 0){
                rema = as[node][idx];
                remb = bs[node][idx];
                remy = ys[node][idx];
            }
            ans = -(as[node].back() - rema) * X - (bs[node].back() - remb)
                 + (ys[node].back() - remy);
            return ans;
        }
        int mid = (lo + hi) >> 1;
        return query(2 * node + 1, lo, mid, ql, qh, X) + query(2 * node + 2, mid + 1, hi, ql, qh, X);
    }
}mx1;

struct MergeSortTree2{
    private:
    vector < pair < int, int > > tree[4 * maxn];
    vector < long long > as[4 * maxn], bs[4 * maxn], ys[4 * maxn];
    int a[4 * maxn];
    public:
    long long op(long long a, long long b){
        // change operation here
        return a + b;
    }
    void build(int node, int lo, int hi){
    if(lo == hi){
        tree[node].push_back({arr[lo].x2, lo});
        as[node].push_back(arr[lo].a);
        bs[node].push_back(arr[lo].b);
        ys[node].push_back(arr[lo].y2);
        return;
    }
    int mid = (lo + hi) >> 1;
    build(2 * node + 1, lo, mid);
    build(2 * node + 2, mid + 1, hi);
    merge(tree[2 * node + 1].begin(), tree[2 * node + 1].end(), tree[2 * node + 2].begin(), tree[2 * node + 2].end(),
            back_inserter(tree[node]));
    as[node].push_back(arr[tree[node][0].second].a);
    for(int i = 1 ; i < (int)tree[node].size(); ++i)
        as[node].push_back(op(as[node][i - 1], arr[tree[node][i].second].a));
    bs[node].push_back(arr[tree[node][0].second].b);
    for(int i = 1 ; i < (int)tree[node].size(); ++i)
        bs[node].push_back(op(bs[node][i - 1], arr[tree[node][i].second].b));
    ys[node].push_back(arr[tree[node][0].second].y2);
    for(int i = 1 ; i < (int)tree[node].size(); ++i)
        ys[node].push_back(op(ys[node][i - 1], arr[tree[node][i].second].y2));
    }
    
    long long query(int node, int lo, int hi, int ql, int qh, int X){
        if(lo > hi || ql > hi || qh < lo) return 0;
        if(ql <= lo && hi <= qh){
            long long ans = 0;
            int idx = upper_bound(all(tree[node]), make_pair(X - 1, maxn)) - tree[node].begin() - 1;
            if(idx < 0) return 0;
            ans = -as[node][idx] * X - bs[node][idx] + ys[node][idx];
            return ans;
        }
        int mid = (lo + hi) >> 1;
        return query(2 * node + 1, lo, mid, ql, qh, X) + query(2 * node + 2, mid + 1, hi, ql, qh, X);
    }
}mx2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) 
        cin >> arr[i].x1 >> arr[i].x2 >> arr[i].y1 >> arr[i].a >> arr[i].b >> arr[i].y2;
    pa[0] = arr[0].a;
    pb[0] = arr[0].b;
    for(int i = 1 ; i < n ; ++i){
        pa[i] = pa[i - 1] + arr[i].a;
        pb[i] = pb[i - 1] + arr[i].b;
    }
    mx1.build(0, 0, n - 1);
    mx2.build(0, 0, n - 1);
    int m;
    cin >> m;
    long long prv = 0;
    while(m--){
        int l, r;
        long long x;
        cin >> l >> r >> x;
        --l; --r;
        x = (x + prv) % mod;
        long long ans = (pa[r] - (l ? pa[l - 1]:0)) * x + (pb[r] - (l ? pb[l - 1]:0));
        ans += mx1.query(0, 0, n - 1, l, r, x) + mx2.query(0, 0, n - 1, l, r, x);
        prv = ans;
        cout << ans << '\n';
    }
    return 0;
}