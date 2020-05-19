#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[3 * maxn], b[3 * maxn];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; ++i)
            cin >> a[i] >> b[i];
        int ad = 2e18, sm = 0;
        for(int i = 0 ; i < n ; ++i){
            sm += max(a[(i + 1) % n] - b[i], 0LL);
            ad = min(ad, a[(i + 1) % n] - max(a[(i + 1) % n] - b[i], 0LL));
        }
        cout << ad + sm << '\n';
    }


    return 0;
}