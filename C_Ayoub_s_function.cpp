#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

long long cnt(long long len){
    return len * (len + 1) / 2LL;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        long long diff = n - m;
        if(diff <= m + 1){
            cout << cnt(n) - diff << '\n';
            continue;
        }
        long long dv = diff / (m + 1), md = diff - dv * m - dv;
        long long sub = cnt(dv) * (m + 1 - md);
        cout << cnt(n) - sub - cnt(dv + 1) * md << '\n';
    }

    return 0;
}
