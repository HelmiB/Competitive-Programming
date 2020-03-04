#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    int ans = 1;
    for(int i = 0 ; i < n ; ++i){
        int cnt = 1;
        for(int j = i + 1 ; j < n ; ++j)
            if(a[j] - a[j - 1] > x) break;
            else cnt++;
        ans = max(cnt, ans);
    }
    cout << ans << '\n';
    return 0;
}
