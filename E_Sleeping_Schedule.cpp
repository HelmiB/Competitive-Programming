#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int dp[2050][2050], a[maxn];
int l, r, n, h;

int solve(int d, int hr){
    if(d == n) return 0;
    int &ret = dp[d][hr];
    if(~ret) return ret;
    int hr1 = (hr + a[d]) % h;
    int hr2 = (hr + a[d] - 1 + h) % h;
    return ret = max((l <= hr1 && hr1 <= r) + solve(d + 1, hr1),
                    (l <= hr2 && hr2 <= r) + solve(d + 1, hr2));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> h >> l >> r;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0) << '\n';
    return 0;
}
