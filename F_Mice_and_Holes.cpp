#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 5050;
const int mod = 1e9 + 7;
long long dp[maxn][maxn], best[maxn];
int x[maxn], acc[maxn];
pair < int, int > hole[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) cin >> x[i];
    sort(x, x + n);
    for(int i = 0 ; i < m ; ++i) cin >> hole[i].first >> hole[i].second;
    sort(hole, hole + m);
    acc[0] = hole[0].second;
    for(int i = 1 ; i < m ; ++i) acc[i] = hole[i].second + acc[i - 1];
    if(acc[m - 1] < n) return cout << -1 << '\n', 0;
    for(int i = 1 ; i <= n ; ++i) best[i] = 1e18;
    for(int i = 0 ; i < m ; ++i){
        deque < pair < long long , int > > dq;
        long long offset = 0;
        dq.push_back({0, 0});
        for(int j = 1 ; j <= min(acc[i], n) ; ++j){
            offset += abs(x[j - 1] - hole[i].first);
            long long x = best[j];
            while(!dq.empty() && dq.front().second < max(0, j - hole[i].second)) dq.pop_front();
            while (!dq.empty() && dq.back().first + offset >= x) dq.pop_back();
            dq.push_back({x - offset,  j});
            dp[i][j] = dq.front().first + offset;
        }
        for(int j = 1 ; j <= min(acc[i], n) ; ++j) best[j] = min(best[j], dp[i][j]);
    }
    cout << dp[m - 1][n] << '\n';
    return 0;
}