#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long double dp[210][210][420], p[maxn];
bool vis[210][210][420];
int a[210], n;

long double solve(int i, int l, int k){
    l = max(0LL, l);
    k = min(400LL, k);
    if(i == n) return !l && k >= 200;
    long double &ret = dp[i][l][k];
    if(vis[i][l][k]) return ret;
    vis[i][l][k] = true;
    ret = p[i] * solve(i + 1, l - 1, k + a[i]) + (1.0 - p[i]) * solve(i + 1, l, k);
    return ret;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int l, k;
    cin >> n >> l >> k;
    for(int i = 0 ; i < n ; ++i){
        int pr;
        cin >> pr;
        p[i] = (long double)pr / 100.0;
    }
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    cout << fixed << setprecision(12) << solve(0, l, k + 200) << '\n';
    return 0;
}