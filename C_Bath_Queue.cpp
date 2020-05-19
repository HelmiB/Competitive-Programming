#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long double dp[51][51][51], C[51][51];
bool vis[51][51][51];
int a[55];
int m;


long double solve(int i, int rem, int len){
    if(!rem) return len;
    if(i == m) return 0;
    long double &ret = dp[i][rem][len];
    if(vis[i][rem][len]) return ret;
    vis[i][rem][len] = true;
    long double pr = 1;
    for(int k = 0 ; k <= rem ; ++k){
        ret += C[rem][k] * pr * solve(i + 1, rem - k, max(len, (k + a[i] - 1) / a[i]));
        pr /= 1.0 * m;
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i) cin >> a[i];
    C[0][0] = 1;
    for(int i = 1 ; i <= 50 ; ++i){
        C[i][0] = 1;
        for(int j = 1 ; j <= i ; ++j) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    cout << fixed << setprecision(20) << solve(0, n, 0) << '\n';
    return 0;
}