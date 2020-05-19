#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
pair < int, int > ed[maxn];
vector < int > g[maxn];

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
        ed[i].first = u, ed[i].second = v;
    }
    vector < int > L;
    for(int i = 1 ; i <= n ; ++i)
        if(sz(g[i]) == 1)
            L.push_back(i);
    if(sz(L) <= 2){
        for(int i = 0 ; i < n - 1 ; ++i) cout << i << '\n';
        return 0;
    }
    int cnt = 3;
    map < pair < int, int > , int > lv;
    for(int i = 0 ; i < 3 ; ++i) lv[{min(L[i], g[L[i]][0]), max(L[i], g[L[i]][0])}] = i;
    for(int i = 0 ; i < n - 1 ; ++i)
        if(lv.find({min(ed[i].first, ed[i].second), max(ed[i].first, ed[i].second)}) != lv.end())
            cout << lv[{min(ed[i].first, ed[i].second), max(ed[i].first, ed[i].second)}] << '\n';
        else cout << cnt++ << '\n'; 
    return 0;
}
