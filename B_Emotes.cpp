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
    int n, m, k;
    cin >> n >> m >> k;
    vector < int > a(n);
    for(auto &x : a) cin >> x;
    sort(all(a));
    int x = a.back();
    a.pop_back();
    int y = a.back();
    cout << (m / (k + 1)) * (x * k + y) + (m % (k + 1)) * x << '\n';
    return 0;
}