#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int dp[1 << 20];
int m;
int cnt[21][21];
int res[21][1 << 20];
int al[21];

/*
int solve(int mask){
    if(__builtin_popcount(mask) == m) return 0;
    int &ret = dp[mask];
    if(~ret) return ret;
    ret = 1e9;
    for(int i = 0 ; i < m ; ++i)
        if(!((1 << i) & mask)){
            int af, bef;
            bef = res[i][mask];
            af = al[i] - bef;
            ret = min(ret, __builtin_popcount(mask) * (bef - af) + solve(mask ^ (1 << i)));            
        }
    return ret;
}
*/

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> m >> m >> s;
    for(int i = 0 ; i < sz(s) - 1 ; ++i)
        if(s[i] != s[i + 1]){
            int a = s[i] - 'a';
            int b = s[i + 1] - 'a';
            cnt[b][a]++;
            cnt[a][b]++;
            al[a]++;
            al[b]++;
        }
    for(int i = 0 ; i < m; ++i){
        for(int j = 0 ; j < (1 << m); ++j){
            if((1 << i) & j) continue;
            for(int k = 0 ; k < m ; ++k)
                if((1 << k) & j)
                    res[i][j] += cnt[i][k];
        }
    }
    for(int i = 0 ; i < (1 << m); ++i) dp[i] = 1e9;
    dp[0] = 0;
    for(int i = 1 ; i < (1 << m); ++i)
        for(int j = 0 ; j < m ; ++j)
            if((1 << j) & i){
                int mask = i ^ (1 << j);
                int bef = res[j][mask];
                int af = al[j] - bef;
                dp[i] = min(dp[i], __builtin_popcount(mask) * (bef - af) + dp[mask]);
            }
    cout << dp[(1 << m) - 1] << '\n';
    return 0;
}