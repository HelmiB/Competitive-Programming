#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[2 * maxn], ans[2 * maxn];
pair < int, int > b[2 * maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    sort(a, a + n);
    for(int i = 0 ; i < m ; ++i) cin >> b[i].first, b[i].second = i;
    sort(b, b + m);
    int l = 0;
    for(int i = 0 ; i < m ; ++i){
        while(l < n && a[l] <= b[i].first) ++l;
        ans[b[i].second] = l;
    }
    for(int i = 0 ; i < m ; ++i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
