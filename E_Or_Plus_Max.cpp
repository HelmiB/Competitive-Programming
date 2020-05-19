#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 18;
const int mod = 1e9 + 7;
pair < int, int > dp[1 << maxn];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < (1 << n) ; ++i) cin >> dp[i].first;
    for(int i = 0 ; i < n ; ++i)
        for(int mask = 0; mask < (1 << n) ; ++mask)
            if(mask & (1 << i)){
                vector < int > v;
                v.push_back(dp[mask].first);
                v.push_back(dp[mask].second);
                v.push_back(dp[mask ^ (1 << i)].first);
                v.push_back(dp[mask ^ (1 << i)].second);
                sort(all(v));
                dp[mask].first = v.back();
                dp[mask].second = v[2];
            }
    int ans = 0;
    for(int i = 1 ; i < (1 << n) ; ++i){
        ans = max(ans, dp[i].first + dp[i].second);
        cout << ans << '\n';
    }
    return 0;
}