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
        int h, n;
        cin >> h >> n;
        vector < int > p(n - 1);
        cin >> h;
        for(auto &x : p) cin >> x;
        int ad = 1;
        while(sz(p)){
            if(p.back() == ad) p.pop_back();
            else break;
            ad++;
        }
        int ans = 0;
        for(int i = 0 ; i < sz(p) ; ++i){
            int j = i;
            int ad = p[i];
            while(j < sz(p) && p[j] == ad){
                ad--;
                ++j;
            }
            ans += (j - i) % 2;
            i = j - 1;
        }
        cout << ans << '\n';
    }

    return 0;
}