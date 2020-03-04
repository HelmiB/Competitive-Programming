#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long double a, b, c;
long double calc(long double i, long double j, long double k){
    long double sm = 0;
    if(a <= EPS && i <= EPS) sm++;
    else sm += a * log(i);
    if(b <= EPS && j <= EPS) sm++;
    else sm += b * log(j);
    if(c <= EPS && k <= EPS) sm++;
    else sm += c * log(k);
    return sm;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int s;
    cin >> s;
    cin >> a >> b >> c;
    long double x = 0, y = 0, z = 0;
    if(a + b + c > 0){
        if(calc(a * s / (a + b + c), b * s / (a + b + c), c * s / (a + b + c)) > calc(0, 0, 0))
        x = a * s / (a + b + c), y = b * s / (a + b + c), z = c * s / (a + b + c);
    }
    cout << fixed << setprecision(15) << x << ' ' << y << ' ' << z << '\n';
    return 0;
}
