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
    while(n--){
        int c, sm;
        cin >> c >> sm;
        int dv = sm / c;
        int left_overs = sm % c;
        cout << left_overs * (dv + 1) * (dv + 1) + (c - left_overs) * dv * dv << '\n';
    }

    return 0;
}