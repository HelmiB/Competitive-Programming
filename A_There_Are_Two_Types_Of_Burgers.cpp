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
        int b, p, f;
        cin >> b >> p >> f;
        int h, c;
        cin >> h >> c;
        int ans = 0;
        for(int i = 0 ; i <= min(b / 2, p); ++i)
            ans = max(ans, h * i + c * min((b - 2 * i) / 2, f));
        cout << ans << '\n';
    }

    return 0;
}