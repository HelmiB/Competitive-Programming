#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

long long get(int X){
    return X * 1LL * (X + 1) / 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector < int > a(n);
    for(auto &x : a) cin >> x;
    a.push_back(0);
    sort(all(a));
    long long ans = 0;
    for(int i = 0 ; i < sz(a) - 1 && m; ++i){
        int l = a[i] + 1, r = a[i + 1] - 1;
        if(l > r) continue;
        r = min(r, l + m - 1);
        m -= r - l + 1; 
        ans += get(r) - get(l - 1);
    }
    if(m) ans += get(a[sz(a) - 1] + m) - get(a[sz(a) - 1]);
    cout << ans << '\n';
    return 0;
}