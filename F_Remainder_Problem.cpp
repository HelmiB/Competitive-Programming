#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
long long ans[750][750], a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while(q--){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            for(int i = 1 ; i < 750 ; ++i)
                ans[i][x % i] += y;
            a[x] += y;
       }else{
           if(x < 750) cout << ans[x][y] << '\n';
           else{
               int cur = y;
               long long ans = 0;
               while(cur < maxn){
                   ans += a[cur];
                   cur += x;
               }
               cout << ans << '\n';
           }
        }
    }
    return 0;
}