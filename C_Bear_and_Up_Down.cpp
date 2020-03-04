#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
int a[maxn], n;

bool check(int l, int r){
    l = max(0, l);
    r = min(r, n - 2);
    for(int i = l; i <= r ; ++i)
        if(i & 1){ if(a[i] <= a[i + 1]) return false;
        }else if(a[i] >= a[i + 1]) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    int idx = -1;
    vector < int > pos;
    for(int i = 0 ; i < n - 1; ++i)
        if(i & 1){
            if(a[i] <= a[i + 1]) idx = i, pos.push_back(i);
        }else if(a[i] >= a[i + 1]) idx = i, pos.push_back(i);
    assert(~idx);
    if(sz(pos) > 10) return cout << 0 << '\n', 0;
    swap(a[idx], a[idx + 1]);
    int ans = check(idx - 2, idx + 2);
    for(auto x : pos) ans &= check(x - 2, x + 2);
    swap(a[idx], a[idx + 1]);
    for(int i = 0 ; i < n ; ++i)
        if(i != idx && i != idx + 1){
            swap(a[idx], a[i]);
            bool ok = check(i - 2, i + 2) && (idx - 2, idx + 2);
            for(auto x : pos) ok &= check(x - 2, x + 2);
            ans += ok;
            swap(a[idx], a[i]);
        }
    idx++;
    for(int i = 0 ; i < n ; ++i)
        if(i != idx && i != idx - 1){
            swap(a[idx], a[i]);
            bool ok = check(i - 2, i + 2) && check(idx - 2, idx + 2);
            for(auto x : pos) ok &= check(x - 2, x + 2);
            ans += ok;
            swap(a[idx], a[i]);
        }
    cout << ans << '\n';
    return 0;
}
