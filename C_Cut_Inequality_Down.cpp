#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int n, L, U;
int a[maxn];
long long h[maxn];
pair < int, int > tree[4 * maxn];

void build(int node, int lo, int hi){
    if(lo == hi){
        tree[node].first = tree[node].second = h[lo];
        return;
    }
    int mid = (lo + hi) >> 1;
    build(2 * node + 1, lo, mid);
    build(2 * node + 2, mid + 1, hi);
    tree[node].first = min(tree[2 * node + 1].first, tree[2 * node + 2].first);
    tree[node].second = max(tree[2 * node + 1].second, tree[2 * node + 2].second);
}

pair < long long, long long > query(int node, int lo, int hi, int ql, int qh){
    if(ql > qh || lo > qh || hi < ql) return {1e18, -1e18};
    if(ql <= lo && hi <= qh) return {tree[node].first, tree[node].second};
    int mid = (lo + hi) >> 1;
    auto ans = query(2 * node + 1, lo, mid, ql, qh);
    auto b = query(2 * node + 2, mid + 1, hi, ql, qh);
    ans.first = min(ans.first, b.first);
    ans.second = max(ans.second, b.second);
    return ans;
}

pair < int , int > get(int node, int lo, int hi, int st, long long sm){
    if(lo == hi){
        if(sm + tree[node].first > U) return {lo, 1};
        else if(sm + tree[node].first < L) return {lo, 0};
        return {-1, -1};
    }
    int mid = (lo + hi) >> 1;
    if(st > mid) return get(2 * node + 2, mid + 1, hi, st, sm);
    auto a = query(node, lo, hi, st, mid);
    if(sm + a.first < L || sm + a.second > U) return get(2 * node + 1, lo, mid, st, sm);
    return get(2 * node + 2, mid + 1, hi, st, sm);
}

struct SparseTable{
    pair < int, int > t[2][maxn],dp[2][maxn][35];
    int lg[maxn];
    SparseTable(){
        lg[1] = 0 ;
        for(int i = 2 ; i < maxn; ++i)
            lg[i] = 1 + lg[i/2];
    }
    void build(int n){
        assert(n < maxn);
        for(int i = 0 ; i <= n; ++i)
            for(int j = 0 ; j <= 20 ; ++j)
                for(int k = 0 ; k < 2 ; ++k)
                    dp[k][i][j] = {-1, -1};
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < 2 ; ++j)
                dp[j][i][0] = t[j][i];
        for(int j = 1 ; j <= 20 ; ++j) 
            for(int i = 0 ; (i + (1 << j)) <= n ; ++i)
                for(int k = 0 ; k < 2 ; ++k){
                    if(dp[k][i][j - 1].first == -1 || dp[dp[k][i][j - 1].second][dp[k][i][j - 1].first + 1][j - 1].first == -1)
                        continue;
                    dp[k][i][j] = dp[dp[k][i][j - 1].second][dp[k][i][j - 1].first + 1][j - 1];
            }    
    }
    pair < int, int > query(int idx, int l , int r){
        assert(l >= 0 && r >= 0 && l < maxn && r < maxn);
        bool ok = true;
        //cout << idx << ' ' << l << ' ' << r << '\n';
        while(ok){
            l++;
            if(l > r) break;
            ok = false;
            for(int j = lg[r - l + 1] ; j >= 0 ; --j)
                if(~dp[idx][l][j].first && dp[idx][l][j].first <= r){
                    //cout << l << ' ' << j << ' ' << idx << '\n';
                    tie(l, idx) = dp[idx][l][j];
                    ok = true;
                    break;
                }
        }
        return {l - 1, idx};
    }
}spt;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> L >> U;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    h[0] = a[0];
    for(int i = 1 ; i < n ; ++i) h[i] = a[i] + h[i - 1];
    build(0, 0, n - 1);
    for(int i = 0 ; i < n ; ++i){
        long long sm = (i ? -h[i - 1]:0) + L;
        spt.t[0][i] = get(0, 0, n - 1, i, sm);
        sm = (i ? -h[i - 1]:0) + U;
        spt.t[1][i] = get(0, 0, n - 1, i, sm);
    }
    spt.build(n);
    int q;
    cin >> q;
    while(q--){
        int b, e;
        long long x;
        cin >> b >> e >> x;
        b--; e--;
        auto st = get(0, 0, n - 1, b, x - (b ? h[b - 1]:0));
        if(st.first == -1 || st.first > e){
            cout << h[e] - (b ? h[b - 1]:0) + x << '\n';
            continue;
        }
        if(st.first == e){
            if(!st.second) cout << L << '\n';
            else cout << U << '\n'; 
            continue;
        }
        auto u = spt.query(st.second, st.first, e);
        //cout << u.first << ' ' << u.second << '\n';
        if(u.first > e){
            cout << h[e] - h[st.first] + (st.second ? U : L ) << '\n';
            continue;
        }
        if(u.first == e){
            if(!u.second) cout << L << '\n';
            else cout << U << '\n';
            continue;
        }
        long long sm = (u.second ? U:L) + h[e] - h[u.first];
        cout << sm << '\n';
    }
    return 0;
}
