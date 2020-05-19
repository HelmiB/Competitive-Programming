#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < int > a[10 * maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    while(m--){
        int l, r, x;
        cin >> l >> r >> x;
        --l; --r;
        int lo = upper_bound(all(a[x]), l - 1) - a[x].begin();
        int hi = upper_bound(all(a[x]), r) - a[x].begin() - 1;        
        if(hi < lo || a[x][hi] < r){
            cout << r + 1 << '\n';
            continue;
        }
        if(a[x][lo] > l){
            cout << l + 1 << '\n';
            continue;
        }
        if(hi - lo == r - l){
            cout << -1 << '\n';
            continue;
        }
        int st = lo;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(a[x][mid] - a[x][st] == mid - st) lo = mid + 1;
            else hi = mid - 1;
        }
        cout << a[x][lo - 1] + 2 << '\n';
    }
    return 0;
}
