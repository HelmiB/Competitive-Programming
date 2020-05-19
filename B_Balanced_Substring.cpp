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
    map < int, int > cnt;
    int ans = 0;
    int n;
    cin >> n;
    string s; cin >> s;
    int ad = 0;
    cnt[0] = -1;
    for(int i = 0 ; i < n; ++i){
        if(s[i] == '0') ad--;
        else ad++;
        if(cnt.count(ad)) ans = max(ans, i - cnt[ad]);
        else cnt[ad] = i;
    }
    cout << ans << '\n';
    return 0;
}