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
    string s;
    cin >> s;
    long long ans = 0;
    for(auto c : s) ans += (c == '4' || c == '8' || c == '0');
    for(int i = 0 ; i < sz(s) - 1 ; ++i){
        string t = "";
        t += s[i];
        t += s[i + 1];
        int x = atoi(t.c_str());
        if(x % 4 == 0) ans += i + 1;
    }
    cout << ans << '\n';
    return 0;
}
