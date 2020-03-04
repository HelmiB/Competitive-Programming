#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[1010], res[1010];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    int ans = 0, idx = -1;
    for(int mid = 0 ; mid < n ; ++mid){
        int sm = a[mid];
        int i = mid - 1, x = a[mid];
        while(i >= 0){
            x = min(x, a[i]);
            sm += x;
            --i;
        }
        i = mid + 1, x = a[mid];
        while(i < n){
            x = min(x, a[i]);
            sm += x;
            ++i;
        }
        if(sm > ans) idx = mid, ans = sm;
    }
    int i = idx - 1, x = a[idx];
    res[idx] = a[idx];
    while(i >= 0){
            x = min(x, a[i]);
            res[i] = x;
            --i;
    }
    i = idx + 1, x = a[idx];
    while(i < n){
        x = min(x, a[i]);
        res[i] = x;
        ++i;
    }
    for(int i = 0 ; i < n ; ++i) cout << res[i] << ' ';
    cout << '\n';
    return 0;
}
