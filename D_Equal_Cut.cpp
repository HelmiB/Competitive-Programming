#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector < int > a(n);
    for(auto &x : a) cin >> x;
    for(int i = 1 ; i < n ; ++i) a[i] += a[i - 1];
    int ans = 3e18;
    for(int mid = 1 ; mid < n - 1 ; ++mid){
        int smL = a[mid];
        int smR = a.back() - a[mid];
        int idxL = 0, idxR = n - 2;
        int lo = 0, hi = mid - 1;
        while(lo <= hi){
            int md = (lo + hi) >> 1;
            if(a[md] <= smL / 2) lo = md + 1;
            else hi = md - 1;
        }
        if(lo) idxL = lo - 1;
        lo = mid + 1, hi = n - 2;
        while(lo <= hi){
            int md = (lo + hi) >> 1;
            if(a[md] - a[mid] <= smR / 2) lo = md + 1;
            else hi = md - 1;
        }
        if(lo) idxR = lo - 1;
        for(int midL = max(0LL, idxL - 1) ; midL < min(mid, idxL + 2) ; ++midL)
            for(int midR = max(mid + 1, idxR - 1) ; midR < min(n - 1, idxR + 2); ++midR){
                vector < int > sms;
                sms.push_back(a[midL]);
                sms.push_back(a[mid] - a[midL]);
                sms.push_back(a[midR] - a[mid]);
                sms.push_back(a.back() - a[midR]);
                sort(all(sms));
                ans = min(ans, sms.back() - sms[0]);
            }
    }
    cout << ans << '\n';
    return 0;
}