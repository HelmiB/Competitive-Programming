#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
bool done[51][51], a[51][51], b[51][51];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            cin >> a[i][j];
    vector < pair < int, int > > res;
    for(int i = 0 ; i < n - 1; ++i)
        for(int j = 0 ; j < m - 1; ++j)
            if(a[i][j] && a[i + 1][j]  && a[i][j + 1]  && a[i + 1][j + 1] ){
                res.push_back({i, j});
                b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
            }
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            if(a[i][j] != b[i][j])
                return cout << -1 << '\n', 0;
    cout << sz(res) << '\n';
    for(auto x : res) cout << x.first + 1  << ' ' << x.second + 1 << '\n';
    return 0;
}