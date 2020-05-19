#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < int > a;
int n, m;

struct MergeSortTree{
    vector < pair < int, int > > tree[4 * maxn];
    vector < int > cumul[4 * maxn];
    pair < int, int > a[4 * maxn];
    long long op(long long a, long long b){
        // change operation here
        return a + b;
    }
    void build(int node, int lo, int hi){
    if(lo > hi) return;
    if(lo == hi){
        tree[node].push_back({a[lo].second, a[lo].first});
        cumul[node].push_back(a[lo].first);
        return;
    }
    int mid = (lo + hi) >> 1;
    build(2 * node + 1, lo, mid);
    build(2 * node + 2, mid + 1, hi);
    merge(tree[2 * node + 1].begin(), tree[2 * node + 1].end(), tree[2 * node + 2].begin(), tree[2 * node + 2].end(),
            back_inserter(tree[node]));
    cumul[node].push_back(tree[node][0].second);
    for(int i = 1 ; i < (int)tree[node].size(); ++i)
        cumul[node].push_back(op(cumul[node][i - 1], tree[node][i].second));
    }
    
    pair < int, int > gr(int node, int lo, int hi, int ql, int qh, int X){
        if(lo > hi || ql > hi || qh < lo) return {0, 0};
        if(ql <= lo && hi <= qh){
            int idx = upper_bound(all(tree[node]), make_pair(X, 0LL)) - tree[node].begin();
            if(idx == sz(tree[node])) return {0, 0};
            return {cumul[node].back() - (idx ? cumul[node][idx - 1]:0), sz(cumul[node]) - idx};
        }
        int mid = (lo + hi) >> 1;
        auto l = gr(2 * node + 1, lo, mid, ql, qh, X);
        auto r = gr(2 * node + 2, mid + 1, hi, ql, qh, X);
        l.first += r.first;
        l.second += r.second;
        return l;
    }
}mt[2];


int dist(int from, int to){
    if(from == to) return 0;
    if(to < from) return m - from + to;
    return to - from;
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    a.resize(n);
    for(auto &x : a) cin >> x;
    int n1 = 0, n2 = 0;
    int ad = 0;
    for(int i = 0 ; i < n - 1 ; ++i){
        ad += dist(a[i], a[i + 1]);
        if(a[i + 1] > a[i]){
            mt[0].a[n1++] = {a[i], a[i + 1]}; 
        }else{
            mt[1].a[n2++] = {a[i], a[i + 1]};
        }
    }
    sort(mt[0].a, mt[0].a + n1);
    sort(mt[1].a, mt[1].a + n2);
    mt[0].build(0, 0, n1 - 1);
    mt[1].build(0, 0, n2 - 1);
    int ans = 1e18;
    int idx1 = 0, idx2 = 0;
    for(int x = 1 ; x <= m ; ++x){
        while(idx1 < n1 && mt[0].a[idx1].first < x) idx1++;
        idx1--;
        while(idx2 < n2 && mt[1].a[idx2].first < x) idx2++;
        idx2--;
        int sm = ad;
        auto l1 = mt[0].gr(0, 0, n1 - 1, 0, idx1, x);
        auto l2 = mt[1].gr(0, 0, n2 - 1, 0, idx2, 0);
        auto r2 = mt[1].gr(0, 0, n2 - 1, idx2, n2 - 1, x);
        sm += l1.second + l1.first - x * l1.second;
        sm -= l2.second * (x - 1) - l2.first;
        sm += r2.first + r2.second * (1 - m) - r2.second * x;
        ans = min(ans, sm);
    }
    cout << ans << '\n';
    return 0;
}