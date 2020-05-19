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
    int n, k;
    cin >> n >> k;
    vector < int > a(n);
    for(auto &x : a) cin >> x;
    long long sm = 0, ad = 0;
    for(int i = 0 ; i < k ; ++i) sm += a[i];
    ad += sm;
    for(int i = k ; i < n; ++i){
        sm -= a[i - k] - a[i];
        ad += sm;
    }
    cout << fixed << setprecision(10) << (long double) ad / (n - k + 1) << '\n';
    return 0;
}