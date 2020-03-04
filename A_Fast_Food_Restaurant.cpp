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
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        if(a) ans++, a--;
        if(b) ans++, b--;
        if(c) ans++, c--;
        if(a < b) swap(a, b);
        if(a < c) swap(a, c);
        if(a && b) ans++, a--, b--;
        if(a && c) ans++, a--, c--;
        if(b && c) ans++, b--, c--;
        if(a && b && c) ans++;
        cout << ans << '\n';
    }

    return 0;
}
