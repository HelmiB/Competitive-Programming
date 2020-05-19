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
    int n;
    cin >> n;
    int sm = 0;
    for(int i = 0 ; i < n ; ++i) cin >> a[i], sm += a[i];
    sort(a, a + n);
    reverse(a, a + n);
    int dv = sm / n, md = sm % n;
    int ans = 0, ad = 0;
    for(int i = 0 ; i < n ; ++i, md--){
        bool flag = (md > 0);
        if(a[i] > dv + flag){
            ans += a[i] - dv - flag;
            ad += a[i] - dv - flag;
        }else ad -= dv + flag - a[i];
    }
    cout << ans << '\n';
    return 0;
}
