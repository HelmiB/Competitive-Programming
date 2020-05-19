#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int dp[330][2 * 301 * 301];
int a[330];
int n;

int solve(int i = 0, int sm = 300 * 301){
    if(i == n){
        if(sm == 300 * 301) return 0;
        return 1e6;
    }
    int &ret = dp[i][sm];
    if(~ret) return ret;
    return ret = min(solve(i + 1, sm + a[i]), 1 + solve(i + 1, sm - a[i]));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    char op = '+';
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        if(op == '-') a[i] *= -1;
        if(i < n - 1) cin >> op;
    }
    memset(dp, -1, sizeof dp);
    cout << (solve(1, 300 * 301 + a[0]) < n ? solve(1, 300 * 301 + a[0])  : -1) << '\n';
    return 0;
}