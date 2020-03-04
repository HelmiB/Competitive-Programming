#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    long long ans = 0;
    map < int , long long > cnt;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        cnt[x - i] += x;
        ans = max(ans, cnt[x - i]);
    }
    cout << ans << '\n';
    return 0;
}
