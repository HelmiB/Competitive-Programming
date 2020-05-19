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
    int t;
    cin >> t;
    while(t--){
        vector < string > v;
        int n, m;
        cin >> n >> m;
        for(int i = 0 ; i < n ; ++i){
            string s;
            cin >> s;
            v.push_back(s);
        }
        vector < int > row(n), col(m);
        for(int i = 0 ; i < n ; ++i){
            int ad = 0;
            for(int j = 0 ; j < m ; ++j)
                ad += v[i][j] == '.';
            row[i] = ad;
        }
        for(int i = 0 ; i < m ; ++i){
            int ad = 0;
            for(int j = 0 ; j < n ; ++j)
                ad += v[j][i] == '.';
            col[i] = ad;
        }
        int ans = 1e9;
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < m ; ++j)
                ans = min(ans, row[i] + col[j] - (v[i][j] == '.'));
        cout << ans << '\n';
    }

    return 0;
}