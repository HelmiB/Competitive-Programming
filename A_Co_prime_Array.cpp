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
    vector < int > res, v(n);
    for(auto &x : v) cin >> x;
    for(int i = 0 ; i < n - 1 ; ++i){
        res.push_back(v[i]);
        if(__gcd(v[i], v[i + 1]) > 1) res.push_back(1);
    }
    res.push_back(v.back());
    cout << sz(res) - n << '\n';
    for(auto x : res) cout << x << ' ';    
    cout << '\n';
    return 0;
}