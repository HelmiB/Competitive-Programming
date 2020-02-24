#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 300500;
const int mod = 1e9 + 7;
int a[maxn], ans[maxn];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    int idx = 0;
    for(int i = 0 ; i < n - 1 ; ++i){
        int d = min(i + 1, n - i - 1);
        ans[n - 2 * d] = max(ans[n - 2 * d], max(a[i], a[i + 1]));
        d = min(i, n - i - 1);
        if(i) ans[n - 2 * d - 1] = max(ans[n - 2 * d - 1], min(a[i], max(a[i - 1], a[i + 1])));
    }
    for(int i = 2 ; i < n ; i += 2) ans[i] = max(ans[i], ans[i - 2]);
    for(int i = 3 ; i < n ; i += 2) ans[i] = max(ans[i], ans[i - 2]);
    ans[n - 1] = *max_element(a, a + n);
    for(int i = 0 ; i < n ; ++i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
