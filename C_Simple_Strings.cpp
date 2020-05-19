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
    for(int i = 1 ; i < sz(s) - 1 ; ++i)
        if(s[i] == s[i - 1] && s[i] == s[i + 1])
            if(s[i] == 'a') s[i] = 'z';
            else s[i] = 'a';
    for(int i = 0 ; i < sz(s) - 1 ; ++i)
        if(s[i] == s[i + 1]){
            for(int j = 0 ; ; ++j)
                if(s[i - 1] != (char)(j + 'a') && s[i] != (char)(j + 'a')){
                    s[i] = (char)(j + 'a');
                    break;
                }
        }
    cout << s << '\n';
    return 0;
}