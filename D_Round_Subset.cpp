#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 10001;
const int mod = 1e9 + 7;
int dp[2][205][5010];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n + 5];
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    for(int j = 0 ; j <= k; ++j)
        for(int x = 0; x <= 5000 ; ++x)
             dp[0][j][x] = -1e9;
    dp[0][0][0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        int tw = 0, fv = 0;
        while(a[i] % 2 == 0) tw++, a[i] /= 2;
        while(a[i] % 5 == 0) fv++, a[i] /= 5;
        for(int x = 0; x <= 5000 ; ++x) dp[i % 2][0][x] = -1e9;
        dp[i % 2][0][0] = 0; 
        for(int j = 1 ; j <= k ; ++j){
            for(int x = 0; x <= 5000 ; ++x) dp[i % 2][j][x] = -1e9;
            for(int x = 0; x <= 5000 ; ++x){
                dp[i % 2][j][x] = max(dp[i % 2][j][x], dp[(i - 1) % 2][j][x]);
                if(x + fv <= 5000){
                     dp[i % 2][j][x + fv] = max(dp[i % 2][j][x + fv], 
                                        dp[(i - 1) % 2][j - 1][x] + tw);
                } 
            }
        }
    }
    int ans = 0;
    for(int x = 1 ; x <= 5000 ; ++x) ans = max(ans, min(x, dp[n % 2][k][x]));
    cout << ans << '\n';
    return 0;
}