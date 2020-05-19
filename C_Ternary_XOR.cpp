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
        int n;
        string s;
        cin >> n >> s;
        bool gr = false;
        string a = "", b = "";
        for(auto c : s){
            int d = c - '0';
            if(d == 1){
                if(!gr){
                    a += "1";
                    b += "0";
                    gr = true;
                }else{
                    a += "0";
                    b += "1";
                }
            }else if(d == 2){
                if(!gr){
                    a += "1";
                    b += "1";
                }else{
                    a += "0";
                    b += "2";
                }
                
            }else{
                a += "0";
                b += "0";
            }
        }
        cout << a << '\n' << b << '\n';
    }

    return 0;
}