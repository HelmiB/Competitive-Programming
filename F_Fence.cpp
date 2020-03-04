#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int dp[205][40100][2], arr[205], sm[205];
int n, a, b;

int solve(int i, int aa, bool prev){
    if(i == n) return 0;
    int &ret = dp[i][aa][prev];
    if(~ret) return ret;
    ret = 1e9;
    int bb = b - sm[i - 1] + a - aa;
    if(aa >= arr[i]) ret = prev * min(arr[i], arr[i - 1]) + solve(i + 1, aa - arr[i], false);
    if(bb >= arr[i]) ret = min(ret, (1 - prev) * min(arr[i], arr[i - 1]) + solve(i + 1, aa, true));
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> a >> b;
    for(int i = 0 ; i < n ; ++i) cin >> arr[i];
    sm[0] = arr[0];
    for(int i = 1 ; i < n ; ++i) sm[i] = arr[i] + sm[i - 1];
    memset(dp, -1, sizeof dp);
    int ans = 1e9;
    if(a >= arr[0]) ans = solve(1, a - arr[0], 0);
    if(b >= arr[0]) ans = min(ans, solve(1, a, 1));
    cout << (ans < 1e9 ? ans:-1) << '\n';
    return 0;
}
