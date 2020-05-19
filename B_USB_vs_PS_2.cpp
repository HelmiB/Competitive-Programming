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
    int a, b, c;
    cin >> a >> b >> c;
    int m;
    cin >> m;
    vector < long long > usb, pc;
    for(int i = 0 ; i < m ; ++i){
        int x;
        string s;
        cin >> x >> s;
        if(s[0] == 'U') usb.push_back(x);
        else pc.push_back(x);
    }
    sort(all(usb)); sort(all(pc));
    for(int i = 1 ; i < sz(usb) ; ++i) usb[i] += usb[i - 1];
    for(int i = 1 ; i < sz(pc) ; ++i) pc[i] += pc[i - 1];
    int ans = 0;
    long long cost = 0;
    for(int i = 0 ; i <= min(sz(usb), a + c) ; ++i){
        int need = (a >= i ? b + c:b + c - (i - a));
        int sm = i + min(sz(pc), need);
        if(sm > ans){
            ans = sm;
            cost = (i ? usb[i - 1]:0) + (min(sz(pc), need) ? pc[min(sz(pc), need) - 1]:0);
        }else if (sm == ans) cost = min(cost, (i ? usb[i - 1]:0) + (min(sz(pc), need) ? pc[min(sz(pc), need) - 1]:0));
    }
    cout << ans << ' ' << cost << '\n';
    return 0;
}