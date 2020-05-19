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
    int l = 0, ans = 0, sm = 0, idxL = 0, idxR = -1;
    for(int r = 0 ; r < n ; ++r){
        sm += !a[r];
        while(sm > k){
            sm -= !a[l];
            ++l;
        }
        if(r - l + 1 > ans){
            ans = r - l + 1;
            idxL = l;
            idxR = r;
        }
    }
    cout << ans << '\n';
    for(int i = idxL ; i <= idxR ; ++i) a[i] = 1;
    for(auto x : a) cout << x << ' ';
    cout << '\n';
    return 0;
}