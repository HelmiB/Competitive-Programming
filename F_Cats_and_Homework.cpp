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
    if(n == 2) return cout << -1 << '\n', 0;
    cout << n / 2 + 1 << ' ' << n / 2 << '\n';    

    return 0;
}