#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

int cnt(long long X){
    string s = to_string(X);
    return sz(s);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long w, m, k;
    cin >> w >> m >> k;
    long long ans = 0;
    long long nb = cnt(m);
    while(true){
        long long ad = (long long)pow(10, nb) - m;
        if(ad > (1e16 + k * nb - 1) / (k * nb) || ad * k * nb > w){
            long long lo = 0, hi = ad;
            while(lo <= hi){
                long long mid = (lo + hi) >> 1;
                if(mid <= (1e16 + k * nb - 1) / (k * nb) && mid * k * nb <= w) lo = mid + 1;
                else hi = mid - 1;
            }
            ans += lo - 1;
            break;
        }
        ans += ad;
        w -= ad * k * nb;
        m = (long long)pow(10, nb);
        nb++;
    }
    cout << ans << '\n';
    return 0;
}