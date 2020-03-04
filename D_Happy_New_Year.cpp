#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
string s, t;
int dp[101][101][2];

int solve(int i, int j, bool st){
    if(i == sz(s) || j == sz(t)) return 0;
    int &ret = dp[i][j][st];
    if(~ret) return ret;
    ret = 0;
    if(st){
        if(s[i] != t[j]) return 0;
        return ret = 1 + solve(i + 1, j + 1, true);
    }
    if(s[i] == t[j]) ret = 1 + solve(i + 1, j + 1, true);
    ret = max({ret, solve(i + 1, j, false), solve(i, j + 1, false)});
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m >> s >> t;
        memset(dp, -1, sizeof dp);
        cout << solve(0, 0, 0) << '\n';
    }
    return 0;
}
