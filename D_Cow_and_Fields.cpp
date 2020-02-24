#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < int > g[maxn];

void solve(int u , int p, int &od, int &ev, bool lv){
    bool ok = false;
    for(auto v : g[u])
        if(v != p)
            solve(v, u, od, ev, !lv), ok = true;
    if(ok){
        od += lv;
        ev += 1 - lv;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n - 1 ; ++i){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int od = 0, ev = 0;
    solve(1, 0, od, ev, 0);
    cout << min(od, ev) << '\n';
    return 0;
}
