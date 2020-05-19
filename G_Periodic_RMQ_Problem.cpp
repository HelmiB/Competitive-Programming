#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
int arr[4 * maxn], tree[4 * maxn], a[maxn], lazy[4 * maxn], prv[4 * maxn];
bool mark[4 * maxn];
int cur, n;
vector < int > pos;

void build(int node, int lo, int hi){
    if(lo == hi){
        arr[node] = a[lo];
        return;
    }
    int mid = (lo + hi) >> 1;
    build(2 * node + 1, lo, mid);
    build(2 * node + 2, mid + 1, hi);
    arr[node] = min(arr[2 * node + 1], arr[2 * node + 2]);
}

int query(int node, int lo, int hi, int ql, int qh){
    if(ql > hi || qh < lo) return 1e9 + 1;
    if(ql <= lo && hi <= qh) return arr[node];
    int mid = (lo + hi) >> 1;
    return min(query(2 * node + 1, lo, mid, ql, qh),
     query(2 * node + 2, mid + 1, hi, ql, qh));
}


vector < int > v;

int get(int l, int r){
    if(r - l + 1 >= n) arr[0];
    if(r / n > l / n){
        l %= n; r %= n;
        return min(get(l, n - 1), get(0, r));
    }
    l %= n; r %= n;
    return query(0, 0, n - 1, l, r);
}

void build2(int node, int lo, int hi){
    if(lo == hi){
        tree[node] = a[pos[lo] % n];
        return;
    }
    int mid = (lo + hi) >> 1;
    build2(2 * node + 1, lo, mid);
    build2(2 * node + 2, mid + 1, hi);
    tree[node] = get(pos[lo], pos[hi]);
}

void push(int node, int lo, int hi){
    if(!lazy[node]) return;
    tree[node] =  prv[node] = lazy[node];
    mark[node] = true;
    if(lo != hi)
        lazy[2 * node + 1] = lazy[2 * node + 2] = lazy[node];
    lazy[node] = 0;
}

void update(int node, int lo, int hi, int ql, int qh, int x){
    push(node, lo, hi);
    if(ql > hi || qh < lo) return;
    if(ql <= lo && hi <= qh){
        lazy[node] = x;
        push(node, lo, hi);
        return;
    }
    int mid = (lo + hi) >> 1;
    update(2 * node + 1, lo, mid, ql, qh, x);
    update(2 * node + 2, mid + 1, hi, ql, qh, x);
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    if(ql <= mid && mid < qh){
        mark[node] = true;
        prv[node] = x;
    }
    if(pos[mid] < pos[mid + 1] - 1 && !mark[node])
     tree[node] = min(tree[node], get(pos[mid] + 1, pos[mid + 1] - 1));
    if(mark[node]) tree[node] = min(tree[node], prv[node]);
}

int query2(int node, int lo, int hi, int ql, int qh){
    push(node, lo, hi);
    if(ql > hi || qh < lo) return 1e9 + 1;
    if(ql <= lo && hi <= qh){
        return tree[node];
    }
    int mid = (lo + hi) >> 1;
    int ans =  min(query2(2 * node + 1, lo, mid, ql, qh),
     query2(2 * node + 2, mid + 1, hi, ql, qh));
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    if(pos[mid] < pos[mid + 1] - 1 && !mark[node]) 
        tree[node] = min(tree[node], get(pos[mid] + 1, pos[mid + 1] - 1));
    if(mark[node]) tree[node] = min(tree[node], prv[node]);
    if(ql <= mid && mid < qh && pos[mid] < pos[mid + 1] - 1 && !mark[node])
        ans = min(ans, get(pos[mid] + 1, pos[mid + 1] - 1));
    if(ql <= mid && mid < qh && mark[node]) ans = min(ans, prv[node]);
    return ans;
}

vector < pair < int, pair < int, int > > > qs;
vector < int > rs;
void brute(int k){
    for(int i = 0 ; i < k ; ++i)
        for(int i = 0 ; i < n ; ++i)
            v.push_back(a[i]);
    for(auto q : qs){
        if(~q.first){
            for(int l = q.second.first ; l <= q.second.second; ++l) v[l] = q.first;
        }else{
            int ans = 1e9 + 1;
            for(int l = q.second.first ; l <= q.second.second; ++l) ans = min(ans, v[l]);
            rs.push_back(ans);
            cout << ans << '\n';
        }
    }
    cout << "-------\n";
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    build(0, 0, n - 1);
    int q;
    cin >> q;
    while(q--){
        int t, l, r;
        cin >> t >> l >> r;
        --l; --r;
        pos.push_back(l);
        pos.push_back(r);
        if(t == 1){
            int x;
            cin >> x;
            qs.push_back({x, {l, r}});
        }else{
            qs.push_back({-1, {l, r}});
        }
    }
    //brute(k);
    pos.push_back(0);
    pos.push_back(n * k - 1);
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());
    build2(0, 0, sz(pos) - 1);
    int idx = 0;
    for(auto q : qs){
        if(~q.first){
            int l = upper_bound(all(pos), q.second.first - 1) - pos.begin();
            int r = upper_bound(all(pos), q.second.second - 1) - pos.begin();
            assert(pos[l] == q.second.first);
            assert(pos[r] == q.second.second);
            update(0, 0, sz(pos) - 1, l, r, q.first);
        }
        else{
            int l = upper_bound(all(pos), q.second.first - 1) - pos.begin();
            int r = upper_bound(all(pos), q.second.second - 1) - pos.begin();
            assert(pos[l] == q.second.first);
            assert(pos[r] == q.second.second);
            cout << query2(0, 0, sz(pos) - 1, l, r) << '\n';
            //assert(rs[idx++] == query2(0, 0, sz(pos) - 1, l, r));
        }
    }
    return 0;
}