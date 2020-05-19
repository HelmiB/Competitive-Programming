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
    sort(all(a));
    int ans = 0;
    for(int i = 0 ; i < n ; ++i){
        while(2 * k < a[i]){
            k = 2 * k;
            ans++;
        }
        k = max(k, a[i]);
    }
    cout << ans << '\n';
    return 0;
}