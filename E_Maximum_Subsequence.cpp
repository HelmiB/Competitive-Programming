#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < int > v;
int n, k, ans, a[50];

void solve(int i, int md){
    if(i == n / 2){
        int md1 = (md + a[i]) % k;
        v.push_back(md);
        if(md1 != md) v.push_back(md1);
        return;
    }
    if(i == n){
        ans = max(ans, (md + v.back()) % k);
        int lo = 0, hi = sz(v) - 1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(md + v[mid] < k) lo = mid + 1;
            else hi = mid - 1;
        }
        ans = (lo ? max(ans, md + v[lo - 1]):0);
        return ;
    }
    solve(i + 1, md);
    solve(i + 1, (md + a[i]) % k);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 0 ; i < n ; ++i) cin >> a[i], a[i] %= k;
    if(n == 1) return cout << a[0] << '\n', 0;
    solve(0, 0);
    sort(all(v));
    solve(n / 2 + 1, 0);
    cout << ans << '\n';
    return 0;
}
