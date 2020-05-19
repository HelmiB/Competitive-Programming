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
    cin >> n;
    if(n == 1){
        int x;
        cin >> x;
        if(!x) cout << "NO" << '\n';
        else cout << "YES" << '\n';
        return 0;
    }
    int on = 0, off = 0;
    for(int i = 0; i < n ; ++i){
        int x;
        cin >> x;
        on += x;
        off += 1 - x;
    }
    if(off != 1) cout << "NO" << '\n';
    else cout << "YES" << '\n';
    return 0;
}