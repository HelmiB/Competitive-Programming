#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int cnt[20];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0, sm = 0;
    for(int i = 1 ; i <= m ; ++i){
        ans += cnt[i] * sm;
        sm += cnt[i];
    }
    cout << ans << '\n';
    return 0;
}
