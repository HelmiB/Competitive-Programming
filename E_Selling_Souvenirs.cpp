#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < long long > g[3];
int best[maxn], maxi;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector < int > one, two, a, b;
    for(int i = 0 ; i < n ; ++i){
        int w, c;
        cin >> w >> c;
        if(w == 1) one.push_back(c), a.push_back(c);
        if(w == 2) two.push_back(c), b.push_back(c);
        if(w == 3) g[0].push_back(c);
    }
    sort(all(one));
    sort(all(two));
    while(sz(two) || sz(one)){
        int u = 0, v = 0;
        if(sz(two)) u = two.back();
        if(sz(one) > 1) v = one.back() + one[sz(one) - 2];
        else if(sz(one)) v = one.back();
        if(u > v){
            two.pop_back();
            g[1].push_back(u);
        }else{
            one.pop_back();
            if(sz(one) >= 1) one.pop_back();
            g[1].push_back(v);
        }
        if(sz(one)) best[sz(g[1]) - 1] = one.back();
    }
    for(int i = 1 ; i < sz(g[1]) ; ++i) g[1][i] += g[1][i - 1];
    sort(all(a));
    sort(all(b));
    if(sz(a)){
        maxi = a.back();
        a.pop_back();
    }
    while(sz(b) || sz(a)){
        int u = 0, v = 0;
        if(sz(b)) u = b.back();
        if(sz(a) > 1) v = a.back() + a[sz(a) - 2];
        else if(sz(a)) v = a.back();
        if(u > v){
            b.pop_back();
            g[2].push_back(u);
        }else{
            a.pop_back();
            if(sz(a) >= 1) a.pop_back();
            g[2].push_back(v);
        }
    }
    for(int i = 1 ; i < sz(g[2]) ; ++i) g[2][i] += g[2][i - 1];
    sort(all(g[0]));
    reverse(all(g[0]));
    long long ans = 0, sm = 0;
    int cap = 0;
    for(int i = 0 ; i <= sz(g[0]); ++i){
        cap += (i > 0) * 3;
        sm += (i ? g[0][i - 1]:0);
        if(cap > m) break;
        if((m - cap) % 2){
            int idx = min(sz(g[2]), (m - cap) / 2) - 1;
            long long ad = sm + maxi;
            if(idx >= 0) ad += g[2][idx];
            ans = max(ans, ad);
        }else{
            int idx = min(sz(g[1]), (m - cap) / 2) - 1;
            long long ad = sm;
            if(idx >= 0) ad += g[1][idx];
            ans = max(ans, ad);
        }
    }
    cout << ans << '\n';
    return 0;
}