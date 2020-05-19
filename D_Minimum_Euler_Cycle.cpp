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
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        cin >> n >> l >> r;
        int i = 1, ad = 2 * (n - 1);
        while(ad < l && i < n){
            ++i;
            if(i == n) break;
            ad += 2 * (n - i);
        }
        ad -= 2 * (n - i);
        ad++;
        int turn = 1;
        while(ad <= r){
            if(ad >= l){
                if(i == n) cout << 1 << ' ';
                else if((turn % 2) == 1) cout << i << ' ';
                else cout << i + (turn >> 1) << ' ';
            }
            if(turn == 2 * (n - i)){
                turn = 0;
                ++i;
            }
            ++turn;
            ++ad;
        }
        cout << '\n';
    }

    return 0;
}