#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < int > a;
int n, k, q;

bool can(int x, int y){
    int ans = 0;
    for(int i = 0 ; i < n ; ++i){
        if(a[i] < x) continue;
        int j = i, cnt = 0;
        while(j < n && a[j] >= x){
            cnt += a[j] <= y;
            ++j;
        }
        ans += max(0LL, min(j - i - k + 1, cnt));
        i = j - 1;
    }
    return ans >= q;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> q;
    a.resize(n);
    vector < int > al;
    for(auto &x : a) cin >> x, al.push_back(x);
    sort(all(al));
    al.erase(unique(all(al)), al.end());
    int ans = 1e18;
    for(int i = 0 ; i < sz(al) ; ++i){
        int lo = i, hi = sz(al) - 1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(can(al[i], al[mid])) hi = mid - 1;
            else lo = mid + 1;
        }
        if(hi < sz(al) - 1) ans = min(ans, al[hi + 1] - al[i]);
    }
    cout << ans << '\n';
    return 0;
}