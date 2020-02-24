#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[maxn];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        long long l = -1, best = 0, k = 0, worst = 2e9 + 5, res = 0;
        for(int i = 0 ; i < n ; ++i)
            if(~a[i]){
                if(i && ~a[i - 1]) res = max(res, abs(a[i] - a[i - 1]));
                if(i < n - 1 && ~a[i + 1]) res = max(res, abs(a[i] - a[i + 1]));
            }else{
                if(i && ~a[i - 1]){
                     best = max(best, a[i - 1]); 
                     worst = min(worst, a[i - 1]); 
                }
                if(i < n - 1 && ~a[i + 1]){
                     best = max(best, a[i + 1]); 
                     worst = min(worst, a[i + 1]); 
                }
            }
        if(best < worst)  cout << res << ' ' << 1 << '\n';
        else cout << max(res, (best - worst + 1) >> 1) << ' ' << ((best + worst) >> 1) << '\n';
    }
    return 0;
}
