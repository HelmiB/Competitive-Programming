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
    int n, p, q;
    cin >> n >> p >> q;
    string s;
    cin >> s;
    int x = 0;
    while(p * x <= n){
        if((n - p * x) % q == 0) break;
        x++;
    } 
    if(x * p > n) return cout << -1 << '\n', 0;
    cout << x + (n - p * x) / q << '\n';
    int l = 0;
    for(int i = 0 ; i < x ; ++i){
        int r = l;
        while(r - l < p) cout << s[r++];
        cout << '\n';
        l = r;
    }
    for(int i = 0 ; i < (n - p * x) / q; ++i){
        int r = l;
        while(r - l < q) cout << s[r++];
        cout << '\n';
        l = r;
    }
    return 0;
}
