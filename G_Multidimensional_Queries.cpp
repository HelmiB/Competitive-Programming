#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
int mini[1 << 5][4 * maxn], maxi[1 << 5][4 * maxn];

void update(int mask, int node, int lo, int hi, int e, int a, int b){
    if(lo == hi){
        mini[mask][node] = a - b;
        maxi[mask][node] = b - a;
        return;
    }
    int mid = (lo + hi) >> 1;
    if(e <= mid) update(mask, 2 * node + 1, lo, mid, e, a, b);
    else update(mask, 2 * node + 2, mid + 1, hi, e, a, b);
    mini[mask][node] = max(mini[mask][2 * node + 1], mini[mask][2 * node + 2]);
    maxi[mask][node] = max(maxi[mask][2 * node + 1], maxi[mask][2 * node + 2]);
}

pair < int, int > ans;
void get(int mask, int node, int lo, int hi, int ql, int qh){
    if(ql > hi || qh < lo) return;
    if(mini[mask][node] <= ans.first && maxi[mask][node] <= ans.second) return;
    if(ql <= lo && hi <= qh){
        ans.first = max(ans.first, mini[mask][node]);
        ans.second = max(ans.second, maxi[mask][node]);
        return;
    }
    int mid = (lo + hi) >> 1;
    get(mask, 2 * node + 1, lo, mid, ql, qh);
    get(mask, 2 * node + 2, mid + 1, hi, ql, qh);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector < int > masks;
    for(int i = 0 ; i < (1 << k) ; ++i){
        int rev = ((1 << k) - 1) ^ i;
        if(rev < i) continue;
        masks.push_back(i);
    }
    for(int i = 0 ; i < 4 * n ; ++i)
        for(auto j : masks)
            maxi[j][i] = mini[j][i] = -1e18;
    for(int i = 0 ; i < n ; ++i){
        vector < int > b(k, 0);
        for(auto &x : b) cin >> x;
        for(auto j : masks){
            int on = 0;
            int off = 0;
            for(int p = 0 ; p < k ; ++p)
                if((1 << p) & j) on += b[p];
                else off += b[p];
            update(j, 0, 0, n - 1, i, on, off);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int i;
            cin >> i;
            --i;
            vector < int > b(k, 0);
            for(auto &x : b) cin >> x;
            for(auto j : masks){
                int on = 0;
                int off = 0;
                for(int p = 0 ; p < k ; ++p)
                    if((1 << p) & j) on += b[p];
                    else off += b[p];
                update(j, 0, 0, n - 1, i, on, off);
            }
        }else{
            int l, r;
            cin >> l >> r;
            --l; --r;
            int best = -1e18;
            for(auto j : masks){
                ans = {-1e18, -1e18};
                get(j, 0, 0, n - 1, l, r);
                best = max(best, ans.first + ans.second);
            }
            cout << best << '\n';
        }
    }   
    return 0;
}