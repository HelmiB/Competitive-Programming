#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector < int > c(n), t(m);
    for(auto &x : c) cin >> x;
    for(auto &x : t) cin >> x;
    sort(all(c));
    sort(all(t));
    int lo = 0, hi = 2e9;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        bool can = true;
        for(int i = 0 ; i < n && can; ++i){
            int idx = upper_bound(all(t), c[i] - 1) - t.begin();
            int l = idx, r = idx - 1;
            if((l < m && l >= 0 && abs(c[i] - t[l]) <= mid) || (r < m && r >= 0 && abs(c[i] - t[r]) <= mid))
                continue;
            can = false;
        }
        if(can) hi = mid - 1;
        else lo = mid + 1;
    }
    cout << hi + 1 << '\n';
    return 0;
}