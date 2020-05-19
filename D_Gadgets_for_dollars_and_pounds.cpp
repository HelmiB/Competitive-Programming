#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1000500;
const int mod = 1e9 + 7;
long long a[maxn], b[maxn];
pair < int, int > d[maxn], p[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = 0 ; i < n ; ++i) cin >> b[i];
    int nd = 0 , np = 0;
    for(int i = 0 ; i < m ; ++i){
        int t, x;
        cin >> t >> x;
        if(t == 1) d[nd++] = {x, i + 1};
        else p[np++] = {x, i + 1};
    }
    sort(d, d + nd);
    sort(p, p + np);
    for(int i = 1 ; i < n ; ++i){
        a[i] = min(a[i], a[i - 1]);
        b[i] = min(b[i], b[i - 1]);
    }
    for(int i = 1 ; i < nd ; ++i) d[i].first += d[i - 1].first;
    for(int i = 1 ; i < np ; ++i) p[i].first += p[i - 1].first;
    int ans = n + 1, dl = -1;
    for(int i = 0 ; i <= min(nd, k) ; ++i){
        if(k - i > np) continue;
        long long dls = (i ? d[i - 1].first:0);
        long long pds = (i == k ? 0:p[k - i - 1].first);
        int lo = 0, hi = n - 1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(a[mid] * dls + b[mid] * pds <= s) hi = mid - 1;
            else lo = mid + 1;
        }
        hi++;
        if(hi == n) continue;
        if(hi + 1 < ans){
            ans = hi + 1;
            dl = i - 1;
        }
    }
    if(ans == n + 1) return cout << -1 << '\n', 0;
    cout << ans << '\n';
    int idx = ans - 1;
    while(idx >= 0 && a[idx] == a[ans - 1]) --idx;
    idx++;
    for(int i = 0 ; i <= dl ; ++i) cout << d[i].second << ' ' << idx + 1 << '\n';
    idx = ans - 1;
    while(idx >= 0 && b[idx] == b[ans - 1]) idx--;
    idx++;
    for(int i = 0 ; i < k - dl - 1; ++i) cout << p[i].second << ' ' << idx + 1 << '\n';
    return 0;
}
