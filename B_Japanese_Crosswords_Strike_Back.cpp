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
    int n, len;
    cin >> n >> len;
    int ad = n - 1;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        ad += x;
    }
    cout << (ad == len ? "YES":"NO") << '\n';
    return 0;
}