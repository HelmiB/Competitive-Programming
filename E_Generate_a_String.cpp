#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long long dp[3][maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    deque < pair < long long, int > > dq;
    for(int i = 1 ; i <= n ; ++i){
        while(!dq.empty() && dq.front().second <= i / 2) dq.pop_front();
        dp[0][i] = min(y + x * 1LL * i + dp[1][i / 2], x * 1LL * i + dp[2][i - 1]);
        if(!dq.empty()) dp[0][i] = min(dp[0][i], y - x * 1LL * i + dq.front().first);
        while (!dq.empty() && dq.back().first >= x * 2LL * i + dp[0][i]) dq.pop_back();
        dq.push_back({x * 2LL * i + dp[0][i],  i});
        dp[1][i] = min(dp[1][i - 1], dp[0][i]  - x * 2LL * i);
        dp[2][i] = min(dp[2][i - 1], dp[0][i]  - x * 1LL * i);
    } 
    cout << dp[0][n] << '\n';
    return 0;
}