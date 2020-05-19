#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

long long calc(long long n, long long m, long long a, long long b, long long c, long long d){
    return a * b * (n - c + 1) * (m - d + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        int k;
        cin >> n >> m >> k;
        vector < pair < int, int > > v(k);
        for(auto &p : v) cin >> p.first >> p.second;
        long long ans = 0;
        for(int mask = 1 ; mask < (1 << k) ; ++mask){
            int a = 1e9, b = 1e9, c = -1, d = -1;
            for(int j = 0 ; j < k ; ++j)
                if(mask & (1 << j)){
                    a = min(a, v[j].first);
                    c = max(c, v[j].first);
                    b = min(b, v[j].second);
                    d = max(d, v[j].second);
                }
            if(__builtin_popcount(mask) & 1) ans += calc(n, m, a, b, c, d);
            else ans -= calc(n, m, a, b, c, d);
        }
        cout << n * 1LL * m * (n + 1) * 1LL * (m + 1) / 4 - ans << '\n';
    }
    return 0;
}