#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long long dp[35][35][55];

long long solve(int n, int m, int k){
    if(n > m) swap(n, m);
    if(!k || k == n * m) return 0;
    if(n == m && n == 1) return 1e12;
    long long &ret = dp[n][m][k];
    if(~ret) return ret;
    ret = 1e12;
    for(int i = 1 ; i <= n - i ; ++i)
        for(int j = 0 ; j <= k ; ++j)
            ret = min(ret, m * m + solve(i, m, j) + solve(n - i, m, k - j));
    for(int i = 1 ; i <= m - i ; ++i)
        for(int j = 0 ; j <= k ; ++j)
            ret = min(ret, n * n + solve(n, i, j) + solve(n, m - i, k - j));
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    memset(dp, -1, sizeof dp);
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        cout << solve(n, m, k) << '\n';
    }

    return 0;
}
