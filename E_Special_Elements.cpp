#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 8010;
const int mod = 1e9 + 7;
short a[maxn];
bool good[maxn];
short in[maxn];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int tc = 1 ; tc <= t ; ++tc){
        int n;
        cin >> n;
        memset(good, false, (n + 1) * sizeof good[0]);
        memset(in, 0, (n + 1) * sizeof in[0]);
        for(int i = 0 ; i < n ; ++i) cin >> a[i], in[a[i]]++;
        int ans = 0;
        for(int i = 0 ; i < n; ++i){
            int ad = a[i];
            for(int j = i + 1 ; j < n ; ++j){
                ad += a[j];
                if(ad > n) break;
                if(in[ad] && !good[ad]){
                    good[ad] = true;
                    ans += in[ad];
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}