#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k, M;
    cin >> n >> k >> M;
    vector < int > tasks(k);
    int ad = 0;
    for(auto &x : tasks) cin >> x, ad += x;
    int ans = 0;
    for(int full = 0 ; full <= n ; ++ full){
        if(full * ad > M) break;
        int sm = M - full * ad, score = (k + 1) * full;
        priority_queue < pair < int, int > > pq;
        for(int i = full + 1; i <= n; ++i) 
            for(int j = 0 ; j < k ; ++j)
                pq.push({-tasks[j], j});
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            if(-u.first > sm) break;
            score++;
            sm += u.first;
        }
        ans = max(ans, score);
    }
    cout << ans << '\n';
    return 0;
}