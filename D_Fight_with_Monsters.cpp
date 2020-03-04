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
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    vector < int > v;
    int ans = 0;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        int md = x % (a + b);
        if(!md){
            v.push_back(b / a + ((b % a) > 0));
            continue;
        }
        if(md <= a){
            ans++;
            continue;
        }
        md -= a;
        v.push_back(md / a + ((md % a) > 0));
    }
    sort(all(v));
    for(int i = 0 ; i < sz(v) && v[i] <= k ; ++i){
        k -= v[i];
        ans++;
    }
    cout << ans << '\n';
    return 0;
}
