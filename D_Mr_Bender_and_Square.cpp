#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int n, x, y;

int cnt(int X){
    return X * (X + 1) / 2ll;
}


int calc(int T){
    int ans = 0;
    int i = T - x;
    i = min(i, y);
    i = max(i , 0LL);
    ans = i * x;
    ans += cnt(T - i) - cnt(max(0LL, T - y));
    return ans;
}


int f(int T){
    int tx = x, ty = y;
    int ans = calc(T + 1);
    x = n - ty + 1, y = tx;
    ans += calc(T + 1);
    x = n - tx + 1, y = n - ty + 1;
    ans += calc(T + 1);
    x = ty, y = n - tx + 1;
    ans += calc(T + 1);
    x = tx;
    y = ty;
    return ans - min(T, n - x) - min(T, x - 1) - min(T, y - 1)  - min(T, n - y) - 3;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c;
    cin >> n >> x >> y >> c;
    int lo = 0, hi = 1e9;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if(f(mid) >= c) hi = mid - 1;
        else lo = mid + 1;
    }
    cout << hi + 1 << '\n';
    return 0;
}
