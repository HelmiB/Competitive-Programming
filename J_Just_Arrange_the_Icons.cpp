#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 2000500;
const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        map < int , int > acc;
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; ++i){
            int x;
            cin >> x;
            acc[x]++;
        }
        int ans = n;
        vector < int > f;
        for(auto x : acc) f.push_back(x.second);
        for(int i = 2 ; i <= f[0] + 1 ; ++i){
            bool can = true;
            int sm = 0;
            for(int j = 0 ; j < sz(f) && can; ++j){
                int dv = f[j] / i, md = f[j] % i;
                if(md > 0){ 
                    md += dv;
                    if(md < i - 1 || md - i + 1 > dv) can = false;
                    else sm += dv + 1;
                }else sm += dv;
            }
            if(can) ans = min(ans, sm);
        }
        cout << ans << '\n';
    }

    return 0;
}
