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
    int ans = 0, n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        int a, b;
        cin >> a >> b;
        ans += b - a;
    }
    cout << ans << '\n';
    return 0;
}