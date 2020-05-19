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
    int n;
    cin >> n;
    vector < int > v(2 * n);
    for(auto &x : v) cin >> x;
    sort(all(v));
    int ans = 1e9;
    for(int i = 0 ; i < sz(v) - 1 ; ++i)
        for(int j = i + 1 ; j < sz(v) ; ++j){
            vector < int > a;
            for(int k = 0 ; k < sz(v) ; ++k)
                if(k != i && k != j)
                    a.push_back(v[k]);
            int ad = 0;
            for(int k = 0 ; k < sz(a) - 1; k += 2)
                ad += a[k + 1] - a[k];
            ans = min(ans, ad);
        }
    cout << ans << '\n';
    return 0;
}