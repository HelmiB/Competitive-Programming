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
        int n;
        cin >> n;
        int x = 0, y = 0;
        bool can = true;
        while(n--){
            int a, b;
            cin >> a >> b;
            if(a < x || b < y) can = false;
            int pl = a - x, cl = b - y;
            if(cl > pl) can = false;
            x = a, y = b;
        }
        cout << (can ? "YES":"NO") << '\n';
    }

    return 0;
}