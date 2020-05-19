#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
int dp[maxn], a[maxn];
int tree[4 * maxn];
multiset < int > in[maxn];

void update(int node, int lo, int hi, int e, int v){
    if(lo == hi){
        tree[node] = v;
        return; 
    }
    int mid = (lo + hi) >> 1;
    if(e <= mid) update(2 * node + 1, lo, mid, e, v);
    else update(2 * node + 2, mid + 1, hi, e, v);
    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
}

int query(int node, int lo, int hi, int ql, int qh){
    if(ql > hi || qh < lo || ql > qh) return - 2 * maxn;
    if(ql <= lo && hi <= qh) return tree[node];
    int mid = (lo + hi) >> 1;
    return max(query(2 * node + 1, lo, mid, ql, qh), query(2 * node + 2, mid + 1, hi, ql, qh));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector < int > Ls;
    Ls.push_back(0);
    for(int i = 1 ; i <= n ; ++i){
        char c, t;
        cin >> c >> t;
        a[i] = (c == 'A' ? 1:-1);
        if(t == 'L') Ls.push_back(i);
    }
    a[0] = 1e5;
    for(int i = 1 ; i <= n ; ++i) a[i] += a[i - 1];
    int j = 0;
    for(int i = 0 ; i < maxn ; ++i) update(0, 0, maxn - 1, i, -2 * maxn);
    for(int i = 1 ; i < Ls[1] ; ++i) dp[i] = -2 * maxn;
    for(int i = Ls[1] ; i <= n ; ++i){
        if(j < sz(Ls) - 1 && Ls[j + 1] == i){
            if(j > 0){
                int l = Ls[j - 1];
                int r = Ls[j];
                for(int k = l ; k < r; ++k){
                    in[a[k]].clear();
                    update(0, 0, maxn - 1, a[k], -2 * maxn);
                }
            }
            int l = Ls[j];
            int r = Ls[j + 1];
            for(int k = l ; k < r; ++k)
                in[a[k]].insert(dp[k]);
            for(int k = l ; k < r; ++k){
                update(0, 0, maxn - 1, a[k], *in[a[k]].rbegin());
            }
            ++j;
        }
        dp[i] = max(1 + query(0, 0, maxn - 1, 0, a[i]),
         query(0, 0, maxn - 1, a[i] + 1, maxn - 1));
    }
    cout << max(0, dp[n]) << '\n';
    return 0;
}