#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

int nxt(int n){
    int ad = sz(to_string(n));
    int d = n / pow(10, ad - 1);
    if(n % (int)pow(10, ad - 1) == 0) return 0;
    int to = 0;
    if(d < 9) to = (d + 1) * pow(10, ad - 1);
    else to = pow(10, ad);
    return to - n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int ad = sz(to_string(n));
    if(n % (int)pow(10, ad - 1) == 0) cout << 1 + nxt(n + 1);
    else cout << nxt(n);
    cout << '\n';
    return 0;
}