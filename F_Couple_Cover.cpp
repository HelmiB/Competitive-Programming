#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 3000001;
const int mod = 1e9 + 7;
long long cnt[maxn], dp[maxn], a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 1 ; i < maxn ; ++i)
        if(cnt[i])
            for(int j = i ; j < maxn ; j += i){
                if(i != j / i) dp[j] += cnt[i] * cnt[j / i];
                else dp[j] += cnt[i] * (cnt[i] - 1);
            }
    sort(a, a + n);
    for(int i = 0 ; i < n ; ++i){
        int lo = i + 1, hi = n - 1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(a[i] * a[mid] >= maxn) hi = mid - 1;
            else lo = mid + 1;
        }
        dp[maxn - 1] += 2LL * (n - hi - 1);
    }
    for(int i = maxn - 2 ; i >= 0 ; --i) dp[i] += dp[i + 1];
    cin >> n;
    while(n--){
        int p;
        cin >> p;
        cout << dp[p] << '\n';
    }
    return 0;
}