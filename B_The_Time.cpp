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
    int h, m;
    char c;
    cin >> h >> c >> m;
    int ad;
    cin >> ad;
    h += ad / 60;
    h %= 24;
    m += ad % 60;
    if(m >= 60) h++, m -= 60;
    h %= 24;
    if(!(h / 10)) cout << 0;
    cout << h << ':';
    if(!(m / 10)) cout << 0;
    cout << m << '\n';

    return 0;
}
