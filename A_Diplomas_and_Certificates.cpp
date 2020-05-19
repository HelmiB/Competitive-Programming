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
    long long n, k;
    cin >> n >> k;
    long long lo = 1, hi = n / 2;
    while(lo <= hi){
        long long mid = (lo + hi) >> 1;
        if((k + 1) <= n / (2 * mid)) lo = mid + 1;
        else hi = mid - 1;
    }
    cout << (lo - 1) << ' ' << k * (lo - 1) << ' ' << n - (k + 1) * (lo - 1) << '\n';
    return 0;
}