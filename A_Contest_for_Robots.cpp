#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    int ad1 = 0, ad2 = 0;
    for(int i = 0; i < n ; ++i){
        int x;
        cin >> x;
        if(!x && a[i]) ad1++;
        if(x && !a[i]) ad2++;
    }
    if(!ad1) return cout << -1 << '\n', 0;
    int dif = ad2 - ad1;
    if(dif < 0) return cout << 1 << '\n', 0;
    dif++;
    int ans = 1 + dif / ad1;
    if(dif % ad1) ans++;
    cout << ans << '\n';
    return 0;
}
