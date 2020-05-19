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
        int n;
        cin >> n;
        if((n >> 1) % 2){
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES\n";
        int x = 2;
        vector < int > od;
        for(int i = 0 ; i < n / 2; i += 2){
            cout << x << ' ' << x + 2 << ' ';
            od.push_back(x - 1);
            od.push_back(x + 3);
            x += 6;
        }
        for(auto x : od) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}