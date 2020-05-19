#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 300500;
const int mod = 1e9 + 7;
int a[maxn], col[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        col[0] = 1;
        for(int i = 1 ; i < n ; ++i)
            if(a[i] != a[i - 1]) col[i] = 3 - col[i - 1];
            else col[i] = col[i - 1];
        if(col[0] == col[n - 1] && a[0] != a[n - 1]){
            int idx = -1;
            for(int i = 1 ; i < n ; ++i)
                if(a[i] == a[i - 1])
                    idx = i;
            if(idx == -1){
                col[n - 1] = 3;
            }else  for(int i = idx ; i < n ; ++i) col[i] = 3 - col[i];
        }
        int ans = 0;
        for(int i = 0 ; i < n ; ++i) ans = max(ans, col[i]);
        cout << ans << '\n';
        for(int i = 0 ; i < n ; ++i) cout << col[i] << ' ';
        cout << '\n'; 
    }

    return 0;
}