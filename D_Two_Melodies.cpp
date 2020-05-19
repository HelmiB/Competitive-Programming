#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int dp[5050][5050], maxmod[10], maxval[maxn], a[5050];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    int ans = 0;
    for(int j = 0 ; j <= n ; ++j){
        memset(maxmod, 0, sizeof maxmod);
        memset(maxval, 0, sizeof maxval);
        for(int i = 0 ; i < j ; ++i){
            dp[i][j] = dp[j][i];
            maxmod[a[i] % 7] = max(maxmod[a[i] % 7], dp[i][j]);
            maxval[a[i]] = max(maxval[a[i]], dp[i][j]);
        }
        for(int i = j + 1 ; i <= n ; ++i){
            dp[i][j] = 1 + max({dp[0][j],
                                maxmod[a[i] % 7],
                                maxval[a[i] + 1],
                                maxval[a[i] - 1]
                            });
            maxmod[a[i] % 7] = max(maxmod[a[i] % 7], dp[i][j]);
            maxval[a[i]] = max(maxval[a[i]], dp[i][j]);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
    return 0;
}