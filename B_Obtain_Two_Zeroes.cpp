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
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(!a && b){
            cout << "NO\n";
            continue;
        }
        int y = (2 * a - b) / 3;
        int z = a - 2 * y;
        if((2 * a - b) % 3  || y < 0 || z < 0){
            cout << "NO\n";
            continue;
        }
        if(a == 2 * y + z && b == 2 * z + y) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}