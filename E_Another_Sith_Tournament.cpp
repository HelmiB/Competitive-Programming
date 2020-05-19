#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long double dp[1 << 18][18];
long double p[19][19];

long double solve(int mask, int L){
    if(!(mask & 1)) return 0.0;
    if(__builtin_popcount(mask) == 1) return 1.0;
    long double &ret = dp[mask][L];
    if(ret >= 0) return ret;
    ret = 0;
    for(int i = 0 ; i < 18 ; ++i)
        if(i != L && (mask & (1 << i)))
            ret = max(ret, p[i][L] * solve(mask ^ (1 << L), i)
            + p[L][i] * solve(mask ^ (1 << i), L));
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if(n == 1) return cout << 1 << '\n', 0;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
            cin >> p[i][j];
    memset(dp, -1, sizeof dp);
    long double ans = 0;
    int mask = (1 << n) - 1;
    for(int i = 0 ; i < n ; ++i)
        for(int j = i + 1 ; j < n ; ++j)
            ans = max(ans, p[i][j] * solve(mask ^ (1 << j), i)
             + p[j][i] * solve(mask ^ (1 << i), j));
    cout << fixed << setprecision(15) << ans << '\n';
    return 0;
}