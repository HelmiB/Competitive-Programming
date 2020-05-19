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
    long long x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << abs(x1 - x2) + abs(y1 - y2) - min(abs(x1 - x2), abs(y1 - y2)) << '\n';
    return 0;
}
