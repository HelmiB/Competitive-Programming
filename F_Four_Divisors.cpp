#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
bool pr[50 * maxn];
vector < long long > p;

void build(){
    memset(pr, true, sizeof pr);
    pr[0] = pr[1] = false;
    for(int i = 2 ; i < 50 * maxn ; ++i)
        if(pr[i]){
            p.push_back(i);
            for(int j = i + i ; j < 50 * maxn ; j += i)
                pr[j] = false;
        }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n, ans = 0;
    cin >> n;
    long long sq = sqrt(n) + 1;
    build();
    for(int i = 0 ; i < sz(p) && p[i] <= sq; ++i){
        int lo = i + 1, hi = sz(p) - 1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(p[mid] * p[i] <= n) lo = mid + 1;
            else hi = mid - 1;
        }
        ans += lo - 1 - i;
        if(p[i] * p[i] * p[i] <= n) ans++;
    }
    cout << ans << '\n';
    return 0;
}