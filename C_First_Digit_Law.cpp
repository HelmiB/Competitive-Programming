#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1050;
const int mod = 1e9 + 7;
long double dp[maxn][maxn];
bool vis[maxn][maxn];
int n, r[maxn], l[maxn];

int calc(int x){
    int ans = 0;
    int cur = 1;
    while(cur <= x){
        ans += min(x - cur + 1, cur);
        if(cur > 1e18 / 10LL + EPS) break;
        cur *= 10;
    }
    return ans;
}

long double solve(int i, int rem){
    if(!rem) return 1;
    if(i == n) return 0;
    long double &ret = dp[i][rem];
    if(vis[i][rem]) return ret;
    vis[i][rem] = true;
    int sm = calc(r[i]) - calc(l[i] - 1), ad = r[i] - l[i] + 1;
    return ret = (long double)sm / ad * solve(i + 1, rem - 1) + 
                (long double)(ad - sm) / ad * solve(i + 1, rem); 
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> l[i] >> r[i];
    int k;
    cin >> k;
    int rem = (n * k + 99) / 100;
    memset(dp, -1, sizeof dp);
    cout << fixed << setprecision(15) << solve(0, rem) << '\n';
    return 0;
}