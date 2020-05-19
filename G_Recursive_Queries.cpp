#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1000500;
const int mod = 1e9 + 7;
int ans[maxn], l[maxn], r[maxn], a[maxn], m, n;


struct RangeBIT{
    struct BIT{
        long long tree[maxn + 10];
        void add(int x, long long v){for(x++; x < maxn; x += x & -x)tree[x] += v;}
        long long get(int x){long long ret = 0; for(x++; x; x -= x & -x)ret += tree[x]; return ret;}
    }b[2];
    void range_add(int l, int r, int v){
        b[0].add(l, v);
        b[0].add(r + 1, -v);
        b[1].add(l, v * (l - 1));
        b[1].add(r+1, -v * r);
    }
    int prefix_sum(int idx){
        return b[0].get(idx) * idx - b[1].get(idx);
    }
    int range_sum(int l, int r){
        return prefix_sum(r) - (l ? prefix_sum(l - 1):0);
    }
}rb[3];


vector < int > ed[maxn];

int calc(int l){
    int ans = 0;
    ans += rb[0].range_sum(l, l);
    int cnt = rb[2].range_sum(l, l);
    int ad = rb[1].range_sum(l, l);
    ans += ad - cnt * l;
    return ans;
}
void solve(){
    for(int i = 0 ; i < 3 ; ++i)
        for(int j = 0 ; j < 2 ; ++j)
            memset(rb[i].b[j].tree, 0, sizeof rb[i].b[j].tree);
    for(int i = 0 ; i < m ; ++i) ed[r[i]].push_back(i);
    stack < pair < int, int > > stk;
    for(int i = 0 ; i < n ; ++i){
        while(!stk.empty() && stk.top().first < a[i]) stk.pop();
        int L = (stk.empty() ? -1:stk.top().second);
        if(L >= 0) rb[0].range_add(0, L, i - L - 1);
        rb[1].range_add(L + 1, i, i);
        rb[2].range_add(L + 1, i, 1);
        stk.push({a[i], i});
        while(sz(ed[i])){
            int idx = ed[i].back();
            ans[idx] += calc(l[idx]);
            ed[i].pop_back();
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = 0 ; i < m ; ++i) cin >> l[i], l[i]--;
    for(int i = 0 ; i < m ; ++i) cin >> r[i], r[i]--;
    solve();
    reverse(a, a + n);
    for(int i = 0 ; i < m ; ++i){
        l[i] = n - 1 - l[i];
        r[i] = n - 1 - r[i];
        swap(l[i], r[i]);
    }
    solve();
    for(int i = 0 ; i < m ; ++i) cout << ans[i] + r[i] - l[i] + 1 << ' ';
    cout << '\n';
    return 0;
}