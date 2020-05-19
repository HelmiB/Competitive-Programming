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
    int a1, l1, a2, l2, c, x, y;
    cin >> a1 >> l1 >> a2 >> l2 >> c >> x >> y;
    for(int i = 0 ; i <= c ; ++i){
        int na1 = a1 + i * x;
        int nl1 = l1 + (c - i) * y;
        int t1 = (l2 + na1 - 1) / na1;
        int t2 = (nl1 + a2 - 1) / a2;
        if(t1 <= t2) return cout << 1 << '\n', 0;
    }
    cout << 0 << '\n';
    return 0;
}