#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int c[30], res[30];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    memset(c, -1, sizeof c);
    for(int i = 0 ; i < sz(s) ; ++i){
        int x = s[i] - 'a';
        res[x] = max(res[x], i - c[x]);
        c[x] = i;
    }
    int ans = 1e9;
    for(int i = 0 ; i < 26 ; ++i) ans = min(ans, max(res[i], sz(s) - c[i]));
    cout << ans << '\n';
    return 0;
}
