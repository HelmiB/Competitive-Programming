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
    int q;
    cin >> q;
    while(q--){
        int n, r;
        cin >> n >> r;
        vector < int > p(n);
        for(auto &x : p) cin >> x;
        sort(all(p));
        int off = 0;
        int ans = 0;
        while(sz(p) && p.back() > off){
            ans++;
            int x = p.back();
            while(sz(p) && p.back() == x) p.pop_back();
            off += r;
        }
        cout << ans << '\n';
    }

    return 0;
}