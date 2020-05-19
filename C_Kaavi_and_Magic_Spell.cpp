#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 3050;
const int mod = 998244353;
int dp[maxn][maxn];
string s, t;

long long add(long long x, long long y) { 
    x += y;
    if(x >= mod) x -= mod;
    if(x < 0) x += mod;
    return x;
}
long long mul(long long x, long long y) { return (add(x, mod) * add(y, mod)) % mod;}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s >> t;
    for(int i = 0 ; i < sz(s) ; ++i)
        dp[i][i] = (i >= sz(t) || (t[i] == s[0]));
    int ans = 0;
    for(int i = 0 ; i < sz(s) - 1 ; ++i)
        for(int j = 0 ; j < sz(s) - i ; ++j){
            if(i + j < sz(s) - 1 && (i + j >= sz(t) - 1 || t[i + j + 1] == s[i + 1]))
                dp[j][i + j + 1] = add(dp[j][i + j + 1], dp[j][i + j]);
            if(j > 0  && j > sz(t) || t[j - 1] == s[i + 1])
                dp[j - 1][i + j] = add(dp[j - 1][i + j], dp[j][i + j]);
        }
    for(int i = sz(s) - 1 ; i >= sz(t) - 1 ; i--) ans = add(ans, dp[0][i]);
    cout << mul(2, ans) << '\n';
    return 0;
}