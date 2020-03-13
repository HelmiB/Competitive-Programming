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
    int k, a, b, c, ta, tb, tc;
    cin >> k >> a >> b >> c >> ta >> tb >> tc;
    set < pair < int, int > > n1, n2, n3;
    for(int i = 0 ; i < a ; ++i) n1.insert({0, i});
    for(int i = 0 ; i < b ; ++i) n2.insert({0, i});
    for(int i = 0 ; i < c ; ++i) n3.insert({0, i});
    int ans = 0;
    for(int i = 0 ; i < k ; ++i){
        auto x = *n1.begin(); n1.erase(x);
        auto y = *n2.begin(); n2.erase(y);
        auto z = *n3.begin(); n3.erase(z);
        int ad = x.first + ta;
        x.first = ad; n1.insert(x);
        ad = max(ad + tb, y.first + tb);
        y.first = ad; n2.insert(y);
        ad = max(ad + tc, z.first + tc);
        z.first = ad; n3.insert(z);
        ans = max(ans, ad);
    }
    cout << ans << '\n';
    return 0;
}
