#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

bool check(int n, int m, int a, int b, int c, int d){
    return (a <= n) && (b <= m) && ((n - a) >= c) && (m >= d);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    vector < pair < int, int > > rec(n);
    for(auto &p : rec) cin >> p.first >> p.second;
    int ans = 0;
    for(int i = 0 ; i < n ; ++i)
        for(int j = i + 1 ; j < n ; ++j){
            int a = rec[i].first, b = rec[i].second;
            int c = rec[j].first, d = rec[j].second;
            if(check(x, y, a, b, c, d) || check(x, y, b, a, c, d) || check(x, y, a, b, d, c) ||
            check(x, y, b, a, d, c) || check(y, x, a, b, c, d) || check(y, x, b, a, c, d) || check(y, x, a, b, d, c) ||
            check(y, x, b, a, d, c))
                ans = max(ans, a * b + c * d);
        }
           
    cout << ans << '\n';
    return 0;
}