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
    long long n;
    int  q;
    cin >> n >> q;
    while(q--){
        string s;
        long long x ;
        cin >> x >> s;
        for(auto c : s){
            long long lo = 1, hi = n;
            long long prv = -1;
            while(1){
                long long mid = (lo + hi) >> 1;
                if(mid == x) break;
                prv = mid;
                if(x > mid) lo = mid + 1;
                else hi = mid - 1;
            }
            if(c == 'L' && lo != hi) x = (x - 1 + lo) >> 1;
            if(c == 'R' && lo != hi) x = (hi + x + 1) >> 1;
            if(c == 'U') x = (~prv ? prv:x);
        }
        cout << x << '\n';
    }
    return 0;
}
