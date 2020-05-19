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
    s += ",";
    string a = "", b = "";
    int l = -1;
    bool can = true;
    bool yes = false;
    for(int i = 0 ; i < sz(s) ; ++i)
        if(s[i] == ',' || s[i] == ';'){
            if(can && (s[l + 1] != '0' || i - l == 2) && l < i - 1){
                if(sz(a)) a += ",";
                a += s.substr(l + 1, i - l - 1);
            }else{
                if(yes) b += ",";
                yes = true;
                b += s.substr(l + 1, i - l - 1);
            }
            l = i;         
            can = true;
        }else can &= (s[i] >= '0' && s[i] <= '9');
    if(!sz(a)) cout << '-' << '\n';
    else cout << '"' << a << '"' << '\n';
    if(!yes) cout << '-' << '\n';
    else cout << '"' << b << '"' << '\n';
    return 0;
}
