#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 998244353;
int dp[102][maxn], sdp[maxn], a[maxn], pos[102][maxn];
long long add(long long x, long long y) { return (x + y + mod) % mod;}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k, len;
    cin >> n >> k >> len;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        pos[max(a[i], 0LL)][i] = 1;
    }
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 0 ; j <= k ; ++j)
            pos[j][i] += pos[j][i - 1];
    sdp[0] = 1;
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= k ; ++j){
            if(~a[i] && a[i] != j) continue;
            dp[j][i] = sdp[i - 1];
            if(len <= i){
                int acc = pos[0][i] - pos[0][i - len] + pos[j][i] - pos[j][i - len];
                if(acc == len) dp[j][i] = add(dp[j][i], add(dp[j][i - len], -sdp[i - len]));
            }
            sdp[i] = add(sdp[i], dp[j][i]);
        }
    cout << sdp[n] << '\n';
    return 0;
}