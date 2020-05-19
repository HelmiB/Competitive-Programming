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
    if(n <= 1){
        cout << n << " 0 0\n";
        return 0;
    }
    vector < int > f;
    f.push_back(0);
    f.push_back(1);
    while(f.back() != n) f.push_back(f[sz(f) - 2] + f.back());
    f.pop_back();
    cout << 0 << ' ' << f.back() << ' ' << f[sz(f) - 2] << '\n';
    return 0;
}