#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

bool good(int x){
    string s = to_string(x);
    reverse(all(s));
    while(s.size() < 6) s += "0";
    reverse(all(s));
    int a = (s[0] - '0') + (s[1] - '0') + (s[2] - '0');
    int b = (s[3] - '0') + (s[4] - '0') + (s[5] - '0');
    return a == b;
}

int dist(int x, string t){
    string s = to_string(x);
    reverse(all(s));
    while(s.size() < 6) s += "0";
    reverse(all(s));
    int ad = 0;
    for(int i = 0 ; i < 6 ; ++i) ad += s[i] != t[i];
    return ad;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int ans = 1e9;
    for(int i = 0 ; i < 1e7 ; ++i)
        if(good(i))
            ans = min(ans, dist(i, s));
    cout << ans << '\n';
    return 0;
}