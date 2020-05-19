#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
bool pr[20 * maxn];

void build(){
    memset(pr, true, sizeof pr);
    pr[0] = pr[1] = false;
    for(int i = 2 ; i < 20 * maxn ; ++i)
        if(pr[i])
            for(int j = i + i ; j < 20 * maxn ; j += i)
                pr[j] = false;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    build();
    int n;
    cin >> n;
    vector < int > a(n);
    int cnt = 0;
    for(auto &x : a) cin >> x, cnt += x == 1;
    sort(all(a));
    int ans = 1;
    vector < int > rs; rs.push_back(a[0]);
    for(int i = 0 ; i < n ; ++i)
        for(int j = i + 1 ; j < n ; ++j)
            if(pr[a[i] + a[j]] && ans < 2){
                ans = 2;
                rs.clear();
                rs.push_back(a[i]);
                rs.push_back(a[j]);
            }
    if(cnt){
        for(int i = cnt ; i < n ; ++i)
            if(pr[a[i] + 1]){
                ans = cnt + 1;
                rs.clear();
                for(int i = 0 ; i < cnt ; ++i) rs.push_back(1);
                rs.push_back(a[i]);
                break;
            }
        if(ans < cnt){
            ans = cnt;
            rs.clear();
            for(int i = 0 ; i < cnt ; ++i) rs.push_back(1);
        }
    }
    cout << ans << '\n';
    for(auto x : rs) cout << x << ' ';
    cout << '\n';
    return 0;
}