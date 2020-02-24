#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000500;
const int mod = 1e9 + 7;
int par[maxn], wp[maxn];
vector < pair < int, int > > g[maxn];
vector < long long > w[maxn], pref[maxn];

void build(int u = 0, int p = -1, int wg = 0){
    par[u] = p;
    wp[u] = wg;
    w[u].push_back(0);
    pref[u].push_back(0);
    for(auto v : g[u])
        if(v.first != p){
            build(v.first, u, v.second);
            for(auto x : w[v.first]) w[u].push_back(x + v.second);
        }
    sort(w[u].begin(), w[u].end());
    for(int i = 1 ; i < (int)w[u].size() ; ++i)
        pref[u].push_back(pref[u][i - 1] + w[u][i]);
}

long long get(int u, long long wi, long long h, long long wp = 0){
    int idx = upper_bound(w[u].begin(), w[u].end(), wi) - w[u].begin();
    long long ans = 0;
    if(idx > 0) ans = (h - wp) * idx - pref[u][idx - 1];
    //cout << " + " << u << ' ' << wi << ' ' << wp << ' ' << ans <<  '\n';
    return ans;
}
long long solve(int u = 0, int child = -1, long long w = 0, long long lst = 0, long long h = 0){
    if(u == -1 || w >= h) return 0;
    long long ans = 0;
    w += lst;
    ans += get(u, h - w, h, w);
    if(~child) ans -= get(child, h - w - lst, h, w + lst);
    return ans + solve(par[u], u, w, wp[u], h);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1 ; i <= n - 1 ; ++i){
        int u = i + 1, w;
        cin >> w;
        g[u - 1].push_back({u / 2 - 1, w});
        g[u/2 - 1].push_back({u - 1, w});
    }
    build();
    for(int i = 0 ; i < m ; ++i){
        int u, h;
        cin >> u >> h;
        --u;
        cout << solve(u, -1, 0, 0, h) << '\n';
    }
    return 0;
}
