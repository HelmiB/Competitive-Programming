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
    long long n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    long long lcm = a / __gcd(a, b) * b;
    cout << p * (n / a - n / lcm) + q * (n / b - n / lcm) + max(p, q) * (n / lcm) << '\n';
    return 0;
}