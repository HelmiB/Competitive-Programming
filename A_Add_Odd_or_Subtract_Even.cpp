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
        int a, b;
        cin >> a >> b;
        if(a == b) cout << 0 << '\n';
        else if (b > a){
            if((b - a) % 2) cout << 1 << '\n';
            else cout << 2 << '\n';
        }else{
            if((b - a) % 2 == 0) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
    }

    return 0;
}
