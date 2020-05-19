#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 300500;
const int mod = 1e9 + 7;
int p[maxn], pos[maxn], foe[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i) cin >> p[i], p[i]--, pos[p[i]] = i;
    for(int i = 0 ; i < n ; ++i) foe[i] = n;
    for(int i = 0 ; i < m ; ++i){
        int l, r;
        cin >> l >> r;
        --l; --r;
        if(pos[l] > pos[r]) swap(l, r);
        foe[pos[l]] = min(foe[pos[l]], pos[r]);
    }
    long long ans = 0;
    int r = n;
    for(int i = n - 1 ; i >= 0; --i){
        r = min(r, foe[i]);
        ans += r - i;
    }
    cout << ans << '\n';
    return 0;
}