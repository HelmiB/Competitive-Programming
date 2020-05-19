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
    long long n;
    cin >> n;
    long long x = 1;
    while(x * (x + 1) / 2 < n) x++;
    x--;
    cout << n - x * (x + 1) / 2<< '\n';

    return 0;
}
