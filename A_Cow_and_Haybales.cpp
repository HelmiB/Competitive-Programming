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
        int n, d;
        cin >> n >> d;
        int ans = 0, dist = 0;
        for(int i = 0 ; i < n ; ++i){
            int x;
            cin >> x;
            if(!i) ans += x;
            else{
                int can = d / dist;
                if(x >= can){
                    ans += can;
                    d = 0;
                }else{    
                ans += x;
                d -= x * dist;
                }
            }
            dist++;
        }
        cout << ans << '\n';
    }

    return 0;
}
