#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

int dig(int x){
    int ans = 0;
    while(x){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 9 ; i < 500000 ; ++i)
        if(i * dig(i + 1) <= (i + 1) * dig(i)){
            bool good = true;
            for(int j = i + 1; j <= 1000; ++j)
                if(i * dig(j) > j * dig(i)){
                    good = false;
                    cout << i << ' ' << j << '\n';
                    return 0;
                }
            cout << i << '\n';
    }
    return 0;
    int k;
    cin >> k;
    for(int i = 1 ; i <= min(k, 9LL) ; ++i)
        cout << i << '\n';
    k -= 9;
    if(k <= 0) return 0;
    int x = 9;
    while(k--){
        x += 10;
        cout << x << '\n';
    }
    return 0 ;
}