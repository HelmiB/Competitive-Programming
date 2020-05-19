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
    int n;
    cin >> n;
    int sm = 0;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        sm += x;
    }
    cin >> n;
    int ans = 1e9;
    for(int i = 0 ; i < n ; ++i){
        int l, r;
        cin >> l >> r;
        if(sm <= r) ans = min(ans, max(l, sm)); 
    }
    cout << (ans == 1e9 ? -1:ans) << '\n';
    return 0;
}