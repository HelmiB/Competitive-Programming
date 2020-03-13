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
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ps = sz(s);
        int ans = 1;
        for(int i = sz(s) - 1 ; i >= 0 ; --i)
            if(s[i] == 'R'){
                ans = max(ans, ps - i);
                ps = i;
            }
        cout << max(ans, ps + 1) << '\n';
    }
    return 0;
}
