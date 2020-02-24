#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long long lev[2][100];

int get(long long X){
    if(X == 1) return 1;
    return 1 + get(X / 2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while(q--){
        int t;
        long long x, k;
        cin >> t;
        if(t <= 2){
            t--;
            cin >> x >> k;
            if(!t) k *= -1LL;
            int L = get(x);
            long long lo = (1ll << (L - 1)), hi = (1ll << L) - 1;
            long long len = hi - lo + 1;
            k %= len;
            lev[t][L] += k;
            lev[t][L] %= len;
        }else{
            cin >> x;
            vector < long long > res;
            res.push_back(x);
            int L = get(x);
            long long lo = (1ll << (L - 1)), hi = (1ll << L) - 1;
            long long len = hi - lo + 1;
            long long ad = x - lo;
            ad -= lev[0][L] - lev[1][L];
            ad = (ad + 3LL * len) % len;
            x = (ad + lo) >> 1;
            while(x){
                int L = get(x);
                long long lo = (1ll << (L - 1)), hi = (1ll << L) - 1;
                long long len = hi - lo + 1;
                assert(x >= lo && x <= hi);
                long long deb = x;
                x -= lo;
                x += lev[0][L];
                x = (x + len) % len;
                res.push_back(x + lo);
                x = deb;
                x -= lo;
                x += lev[1][L];
                x = (x + len) % len;
                x = (x + lo) >> 1;
            }
            for(auto u : res) cout << u << ' ';
            cout << '\n';
        }
    }
    return 0;
}
