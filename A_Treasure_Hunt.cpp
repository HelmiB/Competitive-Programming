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
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a, b;
    cin >> a >> b;
    int dx = abs(x1 - x2) / a, dy = abs(y1 - y2) / b;
    if(abs(x1 - x2) % a || abs(y1 - y2) % b) return cout << "NO" << '\n', 0;
    int d = min(dx, dy);
    dx -= d; dy -=d;
    if(dx < dy) swap(dx, dy);
    cout << (dx % 2 ? "NO":"YES") << '\n'; 

    return 0;
}