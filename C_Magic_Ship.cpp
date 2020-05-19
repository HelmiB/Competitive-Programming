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
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;
    int n;
    string s;
    cin >> n >> s;
    int dx = 0, dy = 0;
    for(auto c : s){
        if(c == 'U') dy++;
        if(c == 'D') dy--;
        if(c == 'R') dx++;
        if(c == 'L') dx--;
    }
    int a = 0, b = 0;
    int ans = 1e18;
    for(int i = 0 ; i < n ; ++i){
        char c = s[i];
        if(c == 'U') b++;
        if(c == 'D') b--;
        if(c == 'R') a++;
        if(c == 'L') a--;
        int lo = 0, hi = 1e9;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            int tx = x0 + a + mid * dx, ty = y0 + b + mid * dy;
            if(abs(tx - x1) + abs(ty - y1) <= mid * n + i + 1) hi = mid - 1;
            else lo = mid + 1;
        }
        if(hi == 1e9) continue;
        ans = min(ans, (hi + 1) * n + i + 1);
    }
    cout << (ans == 1e18 ? -1:ans) << '\n';
    return 0;
}