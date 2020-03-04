#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long long dp[5010][5010];

long long add(long long x, long long y) { 
        x += y;
        if(x >= mod) x -= mod;
        if(x < 0) x += mod;
        return x;
    }
long long mul(long long x, long long y) { return (add(x, mod) * add(y, mod)) % mod; }

int solve(int s, int b){
    if(b == 0) return 1;
    if(b < 0 || s <= 0) return 0;
    int &ret = dp[s][b];
    if(~ret) return ret;
    return ret = add(add(solve(s, b - s), mul(2, solve(s - 1, b))), -solve(s - 2, b)); 
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector < int > v;
    int s, b;
    cin >> s >> b;
    /*b -= s;
    for(int i = 0 ; i <= s ; ++i) dp[i][0] = 1;
    for(int i = 1 ; i <= s ; ++i)
        for(int j = 1 ; j <= b ; ++j)
            for(int k = 1 ; k <= min(i, j); ++k)
                dp[i][j] = add(dp[i][j], mul(i - k + 1, dp[k][j - k]));
    cout << dp[s][b] << '\n';*/
    memset(dp, -1, sizeof dp);
    cout << solve(s, b - s) << '\n';
    return 0;
}
