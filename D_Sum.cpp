#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[maxn];
string ans;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) ans += "+";
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    int sm = 0;
    for(int i = n - 1 ; i >= 0 ; --i)
        if(sm < 0) sm += a[i];
        else sm -= a[i], ans[i] = '-';
    if(sm < 0 || sm > a[0]) 
        for(int i = 0 ; i < n ; ++i)
            ans[i] = (ans[i] == '+' ? '-':'+');
    cout << ans << '\n';
    return 0;
}
