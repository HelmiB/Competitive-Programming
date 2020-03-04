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
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 25 ; i >= 1 ; --i){
        char c = (char)('a' + i);
        char prv = (char)('a' + i - 1);
        bool ok = true;
        while(ok){
            ok = false;
            string res;
            for(int i = 0 ; i < sz(s) ; ++i)
                if(s[i] == c && (((i && s[i - 1] == prv)) || (i < sz(s) - 1 && s[i + 1] == prv))) ok = true;
                else res += s[i];
            ans += sz(s) - sz(res);
            s = res;
        }
    }
    cout << ans << '\n';
    return 0;
}
