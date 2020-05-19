#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
bool dp[1010], can[1010];
int a[10 * maxn];
int n, x;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for(int i = 0 ; i < n ; ++i) cin >> a[i], a[i] %= x;
    for(int i = 0 ; i < n ; ++i){
        memset(can, false, sizeof can);
        for(int j = 0 ; j < x ; ++j)
            if(dp[j] && !dp[(j + a[i]) % x])
                can[(j + a[i]) % x] = true;
        for(int j = 0 ; j < x ; ++j) dp[j] |= can[j];
        dp[a[i]] = true;
    }
    cout << (dp[0] ? "YES":"NO") << '\n';
    return 0;
}