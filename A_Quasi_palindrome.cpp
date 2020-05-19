#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

bool ispal(string s){
    int l = 0, r = sz(s) - 1;
    while(l < r){
        if(s[l] != s[r]) return false;
        l++; r--;
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    reverse(all(s));
    for(int i = 0 ; i < 20 ; ++i){
        if(ispal(s)) return cout << "YES\n", 0;
        s += "0";
    }
    cout << "NO\n";
    return 0;
}