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
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    sort(a, a + n);
    reverse(a, a + n);
    int i;
    for(i = 0 ; i < n && m > 0; ++i) m -= a[i];
    cout << i << '\n';
    return 0;
}
