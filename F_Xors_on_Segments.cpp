#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 50001;
const int mod = 1e9 + 7;
int a[maxn], ans[maxn], l[maxn], r[maxn], dp[maxn];

int get(int x){
    int md = x % 4;
    if(!md) return x;
    if(md == 1) return 1;
    if(md == 2) return x + 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = 0 ; i < m ; ++i) cin >> l[i] >> r[i], l[i]--, r[i]--;
    for(int i = 0 ; i < n ; ++i){
        int best = 0;
        for(int j = i ; j < n ; ++j){
            best = max(best, get(a[i]) ^ get(a[j]) ^ (a[i] < a[j] ? a[i]:a[j]));
            dp[j] = best;
        }
        for(int j = 0 ; j < m ; ++j)
            if(l[j] <= i && i <= r[j])
                ans[j] = max(ans[j], dp[r[j]]);
    }
    for(int i = 0 ; i < m ; ++i) cout << ans[i] << '\n';
    return 0;
}
