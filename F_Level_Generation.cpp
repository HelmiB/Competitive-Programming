#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

int calc(int n, int brid){
    int rem = n - brid;
    return brid + min(rem * 1LL * (rem - 1) / 2, 1LL * brid);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        if(n <= 1){
            cout << 0 << '\n';
            continue;
        }
        int lo = ((n + 1) >> 1) - 1, hi = n - 1;
        while (hi - lo > 1){
            int mid = (hi + lo) >> 1;
            if (calc(n, mid) > calc(n, mid + 1))  hi = mid;
            else lo = mid; 
        }
        cout << calc(n, lo + 1) << '\n';
    }

    return 0;
}