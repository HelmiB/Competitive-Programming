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
    for(auto &x : a) cin >> x;
    vector < int > v, st;
    for(int i = 0 ; i < n ; ++i){
        v.push_back(a[i]);
        if(a[i]){
            st.push_back(1);
            continue;
        }
        int j = i;
        while(j < n && !a[j]) ++j;
        st.push_back(j - i);
        i = j - 1;
    }
    int ans = 0;
    for(int i = 0 ; i < sz(v) ; ++i){
        int sm = v[i], xr = v[i];
        ans += st[i] * (st[i] + 1) / 2;
        for(int j = i + 1 ; j < min(sz(v), i + 50); ++j){
            sm += v[j];
            xr ^= v[j];
            ans += (sm == xr) * st[i] * st[j]; 
        }
    }
    cout << ans << '\n';
    return 0;
}