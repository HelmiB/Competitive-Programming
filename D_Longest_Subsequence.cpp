#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1000500;
const int mod = 1e9 + 7;
vector < int >  cnt[maxn];
int res[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        if(x > m) continue;
        cnt[x].push_back(i + 1);
    }
    int ans = 0, idx = -1;
    for(int i = 1 ; i <= m ; ++i)
        if(sz(cnt[i]))
            for(int j = i ; j <= m ; j += i)
                res[j] += sz(cnt[i]);
    for(int i = 0 ; i <= m ; ++i)
        if(res[i] > ans){
            ans = res[i];
            idx = i;
        }
    if(idx == -1){
        cout << "1 0 \n";
        return 0;
    }
    cout << idx << ' ' << ans << '\n';
    vector < int > rs;
    for(int i = 1 ; i <= idx ; ++i)
        if(idx % i == 0){
            for(auto x : cnt[i]) rs.push_back(x);
        }
    sort(all(rs));
    for(auto x : rs) cout << x << ' ';
    cout << '\n';
    return 0;
}
