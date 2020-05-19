#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1005000;
const int mod = 1e9 + 7;
vector < int > occ[maxn];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector < int > a(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        occ[a[i]].push_back(i);
    }
    long double ans = 0, sm = 0;
    for(int i = n - 1 ; i >= 0 ; --i){
        int cur = sm;
        if(occ[a[i]].back() == i) cur += n - i;
        else{
            int lo = 0, hi = sz(occ[a[i]]) - 1;
            while(lo <= hi){
                int mid = (lo + hi) >> 1;
                if(occ[a[i]][mid] > i) hi = mid - 1;
                else lo = mid + 1;
            }
            assert(hi + 1 < sz(occ[a[i]]));
            cur += occ[a[i]][hi + 1] - i;
        }
        ans += 2.0 / (long double)(n * n) * (cur - 1) + 1.0 / (long double)(n * n);
        sm = cur;
    }
    cout << fixed << setprecision(6) << ans << '\n';
    return 0;
}