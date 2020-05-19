#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b));}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long x, y;
    vector < long long > pr;
    cin >> x >> y;
    long long a = x;
    for(long long i = 2 ; i * i <= x ; ++i)
        if(x % i == 0){
            pr.push_back(i);
            while(x % i == 0) x /= i;
        }
    if(x > 1) pr.push_back(x);
    long long ans = 0;
    while(y){
        long long g = gcd(a, y);
        long long best = 1e18;
        for(auto x : pr){
            if(a % (x * g) != 0) continue;
            if(x * g >= y) continue;
            long long op = (y - (y / (x * g)) * (x * g)) / g;
            if(op < best) best = op;
        }
        if(best == 1e18) ans += y / g, y = 0;
        else{
            ans += best;
            y -= best * g;
        }
    }
    cout << ans << '\n';
    return 0;
}