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
    long long ans = 0;
    string s = "";
    int n, p;
    cin >> n >> p;
    for(int i = 0 ; i < n ; ++i){
        string t;
        cin >> t;
        if(t.back() == 's') s += "1";
        else s += "0";
    }
    long long cur = 0;
    reverse(all(s));
    for(auto c : s){
        cur *= 2LL;
        if(c == '1'){
            ans += p / 2;
            cur++;
        }
        ans += (cur / 2) * p;
    }
    cout << ans << '\n';
    return 0;
}