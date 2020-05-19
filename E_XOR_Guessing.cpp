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
    int res = 0;
    cout << "? ";
    for(int i = 1 ; i <= 100 ; ++i)
        cout << (i << 7) << ' ';
    cout << '\n';
    cout << flush;
    int rep;
    cin >> rep;
    for(int i = 0 ; i < 7 ; ++i)
        if(rep & (1 << i))
            res += (1 << i);
    cout << "? ";
    for(int i = 0 ; i < 100 ; ++i)
        cout << i << ' ';
    cout << '\n';
    cout << flush;
    cin >> rep;
    for(int i = 7 ; i < 14 ; ++i)
        if(rep & (1 << i))
            res += (1 << i);
    cout << "! " << res << '\n';
    cout << flush;
    return 0;
}