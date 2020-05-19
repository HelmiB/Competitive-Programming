#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const int maxn = 100500;
const int mod = 1e9 + 7;
long long dp[maxn][3], a[maxn][3];
int xf, yf, off;
long long solve(int i, int j, vector < vector < bool > > vis){
    if(i == xf && j == yf) return a[j][i];
    vis[j][i - off] = true;
    long long ans = -1e18;
    for(int k = 0 ; k < 4 ; ++k){
        int x = i + dx[k], y = j + dy[k];
        if(x > xf || x < off || y < 0 || y > 2 || vis[y][x - off]) continue;
        ans = max(ans, a[j][i] + solve(x, y, vis));
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int j = 0 ; j < 3 ; ++j)
        for(int i = 1 ; i <= n ; ++i)
            cin >> a[i][j];
    for(int j = 0 ; j < 3 ; ++j) dp[1][j] = (j ? dp[1][j - 1]:0) + a[1][j];
    for(int i = 2 ; i <= n ; ++i){
        dp[i][0]=max(dp[i-1][0]+a[i][0],dp[i-1][1]+a[i][1]+a[i][0]);
        dp[i][0]=max(dp[i][0],dp[i-1][2]+a[i][2]+a[i][1]+a[i][0]);
        dp[i][0]=max(dp[i][0],dp[i-2][2]+a[i-1][2]+a[i][2]+a[i][1]+a[i-1][1]+a[i-1][0]+a[i][0]);
        dp[i][1]=max(dp[i-1][0]+a[i][0]+a[i][1],dp[i-1][1]+a[i][1]);
        dp[i][1]=max(dp[i][1],dp[i-1][2]+a[i][2]+a[i][1]);
        dp[i][2]=max(dp[i-1][0]+a[i][0]+a[i][1]+a[i][2],dp[i-1][1]+a[i][1]+a[i][2]);
        dp[i][2]=max(dp[i][2],dp[i-1][2]+a[i][2]);
        dp[i][2]=max(dp[i][2],dp[i-2][0]+a[i-1][0]+a[i][0]+a[i][1]+a[i-1][1]+a[i-1][2]+a[i][2]);
    }
    cout << dp[n][2] << '\n';
    return 0;
}