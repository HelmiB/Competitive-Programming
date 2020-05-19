#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long long p[2 * maxn];
int a[2 * maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i], p[a[i]] = i + 1;
    long long ans = 0;
    int cur = p[1];
    for(int i = 2 ; i <= n ; ++i) ans += abs(p[i] - cur), cur = p[i];
    cout << ans << '\n';
    return 0;
}
