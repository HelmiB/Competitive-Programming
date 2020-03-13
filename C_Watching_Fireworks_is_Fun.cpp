#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
long long dp[maxn], dp1[maxn];
pair < pair < long long, long long > , long long > fw[400];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n, m, d;
    cin >> n >> m >> d;
    long long prv = 1;
    for(int i = 1 ; i <= m ; ++i) cin >> fw[i].first.first >> fw[i].first.second >> fw[i].second;
    fw[m + 1].second = 3e9;
    long long ans = -1e18;
    for(int j = 1 ; j <= m ; ++j){
        ans = -1e18;
        long long a = fw[j].first.first;
        long long b = fw[j].first.second;
        for(int i = 1 ; i <= n ; ++i) dp1[i] = dp[i];
        deque < pair < long long, long long > > sm, gr;
        int L = 1, R = 1;
        for(long long i = 1 ; i <= n ; ++i){
            long long l = max(1LL, i - d * (fw[j + 1].second - fw[j].second)), r = min(n, i + d * (fw[j + 1].second - fw[j].second));
            while(R <= r){
                if(R <= a){
                    while(sz(sm) && sm.back().first <= dp1[R] + R) sm.pop_back();
                    sm.push_back({dp1[R] + R, R++});
                    while(sm.front().second < l) sm.pop_front();
                }
                else {
                    while(sz(gr) && gr.back().first <= dp1[R] - R) gr.pop_back();
                    gr.push_back({dp1[R] - R, R++});
                    while(gr.front().second < l) gr.pop_front();
                }
            }
            while(sz(sm) && sm.front().second < l) sm.pop_front();
            while(sz(gr) && gr.front().second < l) gr.pop_front();
            dp[i] = b + max(-a + (sz(sm) ? sm.front().first:-1e18), a + (sz(gr) ? gr.front().first:-1e18));
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << '\n';
    return 0;
}
