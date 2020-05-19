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
    int n, w;
    cin >> n >> w;
    vector < int > a(n), rs;
    int ad = 0;
    for(auto &x : a) cin >> x, ad += (x + 1) / 2, rs.push_back((x + 1) / 2);
    if(w < ad) return cout << -1 << '\n', 0;
    w -= ad;
    while(w > 0){
        int idx = -1;
        for(int i = 0 ; i < n ; ++i)
            if(rs[i] < a[i] && (idx == -1 || a[i] > a[idx])){
                idx = i;
            }
        assert(~idx);
        int ad = min(w, a[idx] - rs[idx]);
        w -= ad;
        rs[idx] += ad;
    }
    for(auto x : rs) cout << x << ' ';
    cout << '\n';
    return 0;
}