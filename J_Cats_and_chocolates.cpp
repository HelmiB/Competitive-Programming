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
    int a, b, x;
    cin >> a >> b >> x;
    bool can = (a % x == 0) || (b % x == 0) || ((a + b) % x == 0);
    cout << (can ? "YES":"NO") << '\n';

    return 0;
}