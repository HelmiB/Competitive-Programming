#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
vector < int > g[maxn];
int rem[maxn], c[maxn], sz[maxn];
stack < int > col[maxn];

long long solve(int u = 0, int p = -1){
    col[c[u]].push(u);
    long long ans = 0;
    sz[u] = 1;
    for(auto v : g[u])
        if(v != p){
            ans += solve(v, u);
            long long sm = sz[v];
            while(col[c[u]].top() != u){
                sm -= sz[col[c[u]].top()];
                col[c[u]].pop();
            }
            sz[u] += sz[v];
            ans += sm * 1LL * (sm - 1) / 2LL;
        }
    if(sz(col[c[u]]) == 1){
        rem[c[u]] += sz[u];
        col[c[u]].pop();
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    int tc = 1;
    while(cin >> n){
        for(int i = 0 ; i <= n ; ++i){
            g[i].clear();
            rem[i] = 0;
        }
        for(int i = 0 ; i < n ; ++i) cin >> c[i];
        for(int i = 0 ; i < n - 1 ; ++i){
            int u, v;
            cin >> u >> v;
            --u; --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        long long ans = n * 1LL * n * 1LL * (n - 1) / 2;
        ans -= solve();
        for(int i = 1 ; i <= n ; ++i){
            int sm = n - rem[i];
            ans -= sm * 1LL * (sm - 1) / 2;
        }
        cout << "Case #" << tc << ": " << ans << '\n';
        ++tc;
    }
    
    return 0;
}
