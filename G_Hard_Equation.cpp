#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
int mod = 1e9 + 7;
map < long long, long long > mp;

long long add(long long x, long long y) { 
    x += y;
    if(x >= mod) x -= mod;
    if(x < 0) x += mod;
    return x;
}
long long mul(long long x, long long y) { return (add(x, mod) * add(y, mod)) % mod; }
long long fast_pow(long long n, long long k){
        if(k == 0) return 1LL;
        long long ans = fast_pow(n, k >> 1);
        ans = mul(ans, ans);
        if(k & 1) ans = mul(n, ans);
        return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        long long a, b;
        mp.clear();
        cin >> a >> b >> mod;
        if(b == 1){
            cout << 0 << '\n';
            continue;
        }
        if(!a && !b){
            cout << 1 << '\n';
            continue;
        }
        long long n = floor(sqrt(mod)) + 1;
        for(long long i = n ; i >= 1 ; --i) mp[fast_pow(a, i * n)] = i;
        for(long long i = 0 ; i < n ; ++i){
            long long ad = mul(b, fast_pow(a, i));
            if(mp.find(ad) == mp.end()) continue;
            long long j = mp[ad];
            long long x = j * n - i;
            if(x >= mod) continue;
            cout << x << '\n';
            break;
        }
    }
    
    return 0;
}
