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
    long long mod = -1e18 , mev = -1e18;
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        long long x;
        cin >> x;
        if(x & 1){
            long long tm = mod;
            mod = max({mod, x, x + mev});
            mev = max(mev, tm + x);
        }else{
            mev = max({mev, x, mev + x});
            mod = max(mod, mod + x);
        }
    }
    cout << mod << '\n';
    return 0;
}