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
    vector < int > a(n);
    for(auto &x : a){
        cin >> x;
        if(x == -1) x = 2;
        else if(x == 0) x = -1;
        else x = -2;
    }
    long double ans = 0;
    long long sm = 0;
    int l = 0;
    for(int r = 0 ; r < n ; ++r){
        while(l <= r && (sm < 0 || a[l] != 2) && l <= r) sm -= a[l++];
        sm += a[r];
        while(l <= r && (sm < -1 || a[l] != 2) && l <= r) sm -= a[l++];
        if(l <= r && (sm >= 0 || (sm - a[r]))){
            long double L = l, R = r;
            if(sm < 0) R -= 0.5;
            ans = max(ans, R - L + 1);
        } 
    }
    cout << ans << '\n';
    return 0;
}