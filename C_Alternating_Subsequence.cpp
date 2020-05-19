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
        vector < int > a(n);
        for(auto &x : a) cin >> x;
        int ans = 0;
        for(int i = 0 ; i < n ; ++i){
            int j = i;
            int ad = -1e18;
            while(j < n && a[i] * a[j] > 0) ad = max(ad, a[j++]);
            ans += ad;
            i = j - 1;
        }
        cout << ans << '\n';
    }

    return 0;
}