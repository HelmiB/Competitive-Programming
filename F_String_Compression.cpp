#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int dp[8080], f[8080][8080];
string s;

int dig(int x){
    int ad = 0;
    while(x){
        ad++;
        x /= 10;
    }
    return ad;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for(int i = 1 ; i <= sz(s) ; ++i){
        f[i][i] = 0;
        for(int j = i + 1 ; j <= sz(s) ; ++j){
            int k = f[i][j - 1];
            while(k > 0 && s[i + k - 1] != s[j - 1]) k = f[i][i + k - 1];
            if(s[j - 1] == s[i + k - 1]) f[i][j] = ++k;
            else f[i][j] = k;
        }
    }
    
    dp[0] = 0;
    for(int i = 1 ; i <= sz(s); ++i){
        dp[i] = 1e9;
        for(int j = 1 ; j <= i ; ++j){
            int len = i - j + 1;
            if(len % (len - f[j][i]) == 0)
                dp[i] = min(dp[i], dp[j - 1] + dig(len / (len - f[j][i])) + len - f[j][i]);
            dp[i] = min(dp[i], dp[j - 1] + 1 + len);
        }
    }
    cout << dp[sz(s)] << '\n';
    return 0;
}