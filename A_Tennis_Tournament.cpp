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
    int n, b, p;
    cin >> n >> b >> p;
    int tw = n * p;
    int bt = 0;
    while(n > 1){
        int pw = log2(n);
        n -= (1 << (pw - 1));
        bt += (2 * b + 1) * (1 << (pw - 1)); 
    }
    cout << bt << ' ' << tw << '\n';
    return 0;
}
