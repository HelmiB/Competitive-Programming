#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long long dp[510][510][2];
bool a[510][510];
int n;

long long add(long long x, long long y) { 
        x += y;
        if(x >= mod) x -= mod;
        if(x < 0) x += mod;
        return x;
    }
long long mul(long long x, long long y) { return (add(x, mod) * add(y, mod)) % mod; }
    

long long solve(int l, int r, bool flag){
    if(l == r - 1) return 1;
    long long &ret = dp[l][r][flag];
    if(~ret) return ret;
    ret = 0;
    if(flag){
        for(int i = l + 1 ; i <= r ; ++i) ret = add(ret, mul(solve(l, i, 1), solve(l, r, 1)))
    }else{
        
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
            cin >> a[i][j];
    for(int i = 0 ; i < n ; ++i) a[n][i] = a[i][n] = a[i][0];
    memset(dp, -1 , sizeof dp);
    cout << solve(0, n, 0) << '\n';
    return 0;
}
