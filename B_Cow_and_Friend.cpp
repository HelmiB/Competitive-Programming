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
        int ans = 1e9;
        int n, x;
        cin >> n >> x;
        for(int i = 0 ; i < n ; ++i){
            int y;
            cin >> y;
            if(y > x) ans = min(ans, 2);
            else if(x % y == 0) ans = min(ans, x / y);
            else ans = min(ans, x / y + 1);
        }
        cout << ans << '\n';
    }

    return 0;
}
