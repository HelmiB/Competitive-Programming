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
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;
        if(n2 > 0)
            for(int i = 0 ; i <= n2 ; ++i) cout << 1;
        if(n0 > 0)
             for(int i = 0 ; i <= n0 ; ++i) cout << 0;
        int n = n1;
        if(n2 == 0 && n0 == 0) n++;
        if(n2 == 0 || n0 == 0) n++;
        int x = n0 > 0;
        for(int i = 0 ; i < n - 1 ; ++i){
            cout << x;
            x = 1 - x;
        }
        cout << '\n';
    }

    return 0;
}