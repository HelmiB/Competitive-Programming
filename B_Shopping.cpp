#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector < int > v(k);
    for(auto &x : v) cin >> x;
    int ans = 0;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j){
            int x;
            cin >> x;
            int idx = 0;
            while(v[idx++] != x);
            ans += idx;
            v.erase(v.begin() + idx - 1);
            v.insert(v.begin(), x);
        }
    cout << ans << '\n';
    return 0;
}