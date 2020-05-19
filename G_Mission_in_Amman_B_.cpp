#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long long a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m, k;
    cin >> m >> k;
    for(int i = 0 ; i < m ; ++i) cin >> a[i];
    sort(a, a + m);
    reverse(a, a + m);
    int lo = 0, hi = 1e9;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        long long ad = 0;
        long long sm = k;
        int lst = -1;
        for(int i = 0 ; i < m; ++i)
            if(a[i] > mid){
                if(a[i] - mid > sm){
                    ad = 1;
                    break;
                }
                ad += a[i] - mid;
                sm -= a[i] - mid;
                if(!i) lst = mid;
            }
            else{
                if(!i) lst = a[i] + min(ad, mid - a[i]);
                ad -= min(ad, mid - a[i]);
            }
        if(!ad) hi = mid - 1;
        else lo = mid + 1;
    }
    cout << hi + 1 << '\n';
    return 0;
}


// 9 4 4 3 1