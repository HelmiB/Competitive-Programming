#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

long long get(int k, int f, int s){
    return k * 1LL * (f + s) / 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n, k;
    cin >> n >> k;
    if((k + 1) / 2 > n / k) return cout << -1 << '\n', 0;
    long long ans = 0, sm = k * (k + 1) / 2;
    for(long long i = 1 ; i * i <= n ; ++i)
        if(n % i == 0){
            long long g = i;
            if(g <= n / sm) ans = max(ans, g);
            g = n / i;
            if(g <= n / sm) ans = max(ans, g);
        }
    if(!ans) return cout << -1 << '\n', 0;
    for(int i = 1; i < k ; n -= i * ans, ++i) cout << i * ans << ' ';
    cout << n << '\n';
    return 0;
}