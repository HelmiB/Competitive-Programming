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
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if((y - x) % (a + b) == 0) cout << (y - x) / (a + b) << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}
