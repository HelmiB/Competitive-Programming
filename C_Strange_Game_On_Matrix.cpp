#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int dp[101][101], a[101][101];
int n, m, k;

int solve(int i, int j){
    if(j == m) return 0;
    if(i == n) return solve(0, j + 1);
    int &ret = dp[i][j];
    if(~ret) return ret;
    if(!a[i][j]) return ret = solve(i + 1, j);
    int ad = 0;
    for(int p = i ; p < min(i + k, n); ++p) ad += a[p][j];
    return ret = max(ad + solve(0, j + 1), solve(i + 1, j));
}

int track(int i, int j){
    if(j == m) return 0;
    if(i == n) return track(0, j + 1);
    if(!a[i][j]) return track(i + 1, j);
    int ad = 0;
    for(int p = i ; p < min(i + k, n); ++p) ad += a[p][j];
    if(ad + solve(0, j + 1) >= solve(i + 1, j)) return track(0, j + 1);
    return 1 + track(i + 1, j);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            cin >> a[i][j];
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << ' ' << track(0, 0) << '\n';
    return 0;
}