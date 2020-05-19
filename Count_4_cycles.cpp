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
    set < pair < int, int > > st;
    for(int i = 0 ; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        st.insert({u, v});
    }
    int ans = 0;
    for(int i = 0 ; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        ans += (st.find({u, v}) != st.end());
    }
    cout << ans << '\n';
    return 0;
}