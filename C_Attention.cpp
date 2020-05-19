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
    string s;
    int n;
    cin >> n >> s;
    vector < int > acc(n + 1);
    acc[n] = 0;
    for(int i = n - 1 ; i >= 0 ; --i)
        acc[i] = acc[i + 1] + (s[i] == 'E');
    int ans = 1e9;
    int w = 0;
    for(int i = 0 ; i < n ; ++i){
        ans = min(ans, w + acc[i + 1]);
        w += s[i] == 'W';
    }
    cout << ans << '\n';
    return 0;
}