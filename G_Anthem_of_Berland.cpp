#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
string s;
int f[100 * maxn];
vector < int > nxt[26];



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s >> t;
    f[0] = 0;
    for(int i = 1 ; i < sz(t) ; ++i){
        int k = f[i - 1];
        while(k > 0 && t[k] != t[i]) k = f[k - 1];
        if(t[k] == t[i]) f[i] = ++k;
        else f[i] = k;
    }
    for(int j = 0 ; j < 26 ; ++j) nxt[j].push_back(t[0] == (char)(j + 'a'));
    for(int i = 1 ; i <= sz(t) ; ++i)
        for(int j = 0 ; j < 26 ; ++j){
            nxt[j].push_back(-1); 
            if(i < sz(t) && t[i] == (char)(j + 'a')) nxt[j][i] = i + 1;
            else nxt[j][i] = nxt[j][f[i - 1]];          
        }
    vector < vector < int > > dp(sz(s), vector < int > (sz(t) + 5, -1));
    if(s[0] == '?'){
        dp[0][1] = sz(t) == 1;
        dp[0][0] = 0;
    }else{
        if(s[0] == t[0]) dp[0][1] = sz(t) == 1;
        else dp[0][0] = 0;
    }
    for(int i = 1 ; i < sz(s) ; ++i)
        if(s[i] == '?'){
            for(int c = 0 ; c < 26 ; ++c)
                for(int j = 0 ; j <= sz(t) ; ++j)
                    if(~dp[i - 1][j])
                        dp[i][nxt[c][j]] = max(dp[i][nxt[c][j]],
                         dp[i - 1][j] + (nxt[c][j] == sz(t)));
        }else{
            int c = s[i] - 'a';
            for(int j = 0 ; j <= sz(t) ; ++j)
                if(~dp[i - 1][j])
                    dp[i][nxt[c][j]] = max(dp[i][nxt[c][j]],
                     dp[i - 1][j] + (nxt[c][j] == sz(t)));
        }
    cout << *max_element(all(dp[sz(s) - 1])) << '\n';
    return 0;
}