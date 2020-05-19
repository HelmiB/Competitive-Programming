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
    vector < int > a(n, 0);
    vector < int > b(n / 2);
    for(auto &x : b) cin >> x;
    int r = 1e18 + 1, l = -1;
    for(int i = 0 ; i < n / 2 ; ++i){
        a[n - i - 1] = b[i];
        int diff = max(0LL, a[n - i - 1] - r);
        a[i] += diff;
        a[n - i - 1] -= diff;
        diff = max(0LL, l - a[i]);
        a[i] += diff;
        a[n - i - 1] -= diff;
        l = a[i];
        r = a[n - i - 1];
    }
    for(auto x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}