#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int dp[maxn], tmp[maxn];
int n;

long long add(long long x, long long y) { 
    x += y;
    if(x >= mod) x -= mod;
    if(x < 0) x += mod;
    return x;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    dp[0] = 1;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        for(int j = 1 ; j * j <= x ; ++j)
            if(x % j == 0){
                tmp[j] = add(dp[j - 1], dp[j]);
                if(j != x / j && x / j <= 1e5) tmp[x / j] = add(dp[x / j - 1], dp[x / j]);
            }
        for(int j = 1 ; j * j <= x ; ++j)
            if(x % j == 0){
                dp[j] = tmp[j];
                if(j != x / j && x / j <= 1e5) dp[x / j] = tmp[x / j];
            }
    }
    for(int i = 1; i < n ; ++i) dp[i + 1] = add(dp[i + 1], dp[i]);
    cout << dp[n] << '\n';
    return 0;
}
