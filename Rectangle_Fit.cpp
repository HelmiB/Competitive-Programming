#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
pair < int , int > pt[maxn];

struct MergeSortTree{
    vector < int > tree[4 * maxn];
    int a[4 * maxn];
    void build(int node, int lo, int hi){
    if(lo == hi){
        tree[node].push_back(a[lo]);
        return;
    }
    int mid = (lo + hi) >> 1;
    build(2 * node + 1, lo, mid);
    build(2 * node + 2, mid + 1, hi);
    merge(tree[2 * node + 1].begin(), tree[2 * node + 1].end(), tree[2 * node + 2].begin(), tree[2 * node + 2].end(),
            back_inserter(tree[node]));
    }
    
    long long query(int node, int lo, int hi, int ql, int qh, int X){
        if(lo > hi || ql > hi || qh < lo) return 0;
        if(ql <= lo && hi <= qh){
            int ans = upper_bound(all(tree[node]), X) - tree[node].begin();
            return ans;
        }
        int mid = (lo + hi) >> 1;
        return query(2 * node + 1, lo, mid, ql, qh, X) + query(2 * node + 2, mid + 1, hi, ql, qh, X);
    }
}mt;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a;
    cin >> n >> a;
    for(int i = 0 ; i < n ; ++i) cin >> pt[i].first >> pt[i].second;
    sort(pt, pt + n);
    for(int i = 0 ; i < n ; ++i) mt.a[i] = pt[i].second;
    mt.build(0, 0, n - 1);
    int ans = 0;
    for(int i = 0 ; i < n ; ++i){
        int L = pt[i].first;
        int R = a / L;
        ans = max(ans, (int)mt.query(0, 0, n - 1, 0, i, R));
    }
    cout << ans << '\n';
    return 0;
}