#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

int dig(long long X){
    int ad = 0;
    while(X){
        ad += X % 10;
        X /= 10;
    }
    return ad;
}
int cnt(long long n, long long s){
    long long l = s, r = min(n, s + 100000);
    int ad = 0;
    for(long long i = l ; i <= r ; ++i)
        ad += (i - dig(i)) < s;
    return ad;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n, s;
    cin >> n >> s;
    cout << max(0LL, n - s + 1) - cnt(n, s) << '\n';
    return 0;
}