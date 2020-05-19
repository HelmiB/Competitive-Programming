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
    vector < int > a(n);
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        a[i] -= i + 1;
    }
    sort(all(a));
    vector < int > l = a;
    for(int i = 1 ; i < sz(l) ; ++i) l[i] += l[i - 1];
    int ans = 3e18;
    for(int i = 0 ; i < n ; ++i){
        int adL = l[i];
        int adR = l.back() - adL;
        int L = i + 1;
        int R = n - L;
        ans = min(ans, adR - adL + L * a[i] - R * a[i]);
    }
    cout << ans << '\n';
    return 0;
}