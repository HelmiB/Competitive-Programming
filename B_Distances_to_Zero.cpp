#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
int p[maxn], s[maxn], a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    if(!a[0]) p[0] = 0;
    else p[0] = - 5 * n;
    if(!a[n - 1]) s[n - 1] = n - 1;
    else s[n - 1] = 5 * n;
    for(int i = 1 ; i < n ; ++i){
        p[i] = p[i - 1];
        if(!a[i]) p[i] = i;
    }
    for(int i = n - 2 ; i >= 0 ; --i){
        s[i] = s[i + 1];
        if(!a[i]) s[i] = i;
    }
    for(int i = 0 ; i < n ; ++i) cout << min(i - p[i], s[i] - i) << ' ';
    cout << '\n';
    return 0;
}