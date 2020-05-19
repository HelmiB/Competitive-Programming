#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int ans = n * (n + 1) / 2 - n;
    vector < int > v;
    for(int i = 0 ; i < sz(s); ++i){
        int j = i;
        while(j < n && s[j] == s[i]) ++j;
        v.push_back(j - i);
        i = j - 1;
    }
    for(int i = 0 ; i < sz(v) - 1 ; ++i) ans -= v[i] + v[i + 1] - 1;
    cout << ans << '\n';
    return 0;
}