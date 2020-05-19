#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[3 * maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n; ++i) cin >> a[i];
    vector < pair < int, int > > ans;
    bool ok = false;
    for(int i = 0; i < n ; ++i){
        map < int, int > cnt;
        int j = i;
        bool can = false;
        while(!can && j < n){
            cnt[a[j]]++;
            if(cnt[a[j]] == 2) can = true;
            ++j;
        }
        if(!can && !ok) return cout << -1 << '\n', 0;
        ok = true;
        if(can) ans.push_back({i + 1, j});
        else ans.back().second = j;
        i = j - 1;
    }
    cout << sz(ans) << '\n';
    for(auto x : ans) cout << x.first << ' ' << x.second << '\n';
    return 0;
}
