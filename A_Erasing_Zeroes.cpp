#include<bits/stdc++.h>
using namespace std;
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
        int l = -1, r = -1;
        int ans = 0;
        for(int i = 0 ; i < (int)s.length() ; ++i)
            if(s[i] == '1'){
                if(l == -1) l = i;
                else r = i;
            }
        for(int i = l ; i <= r ; ++i)
            ans += (s[i] == '0');
        cout << ans << '\n';
    }

    return 0;
}
