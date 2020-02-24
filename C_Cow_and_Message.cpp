#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long long dp[50][50], ad[50];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    long long ans = 0;
    for(int i = 0 ; i < sz(s) ; ++i){
        for(int j = 0 ; j < 26 ; ++j)
            dp[j][s[i] - 'a'] += ad[j];
        ad[s[i] - 'a']++;
    }
    for(int i = 0 ; i < 26 ; ++i){
        for(int j = 0 ; j < 26 ; ++j)
            ans = max(ans, dp[i][j]);
        ans = max(ans, ad[i]);
    }
    cout << ans << '\n';
    return 0;
}
