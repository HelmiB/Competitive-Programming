#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
vector < int > g[maxn];
vector < int > leaves;

int solve(int u = 0, int p = -1, int lvl = 0){
    if(!u){
        int ans = 0;
        for(auto v : g[u])
            ans = max(ans, 1 + solve(v, u));
        return ans;
    }
    if(sz(g[u]) == 1 && u) leaves.push_back(lvl); 
    for(auto v : g[u])
        if(v != p)
            solve(v, u, lvl + 1);
    if(!p){
        sort(all(leaves));
        int res = leaves[0];
        for(int i = 1 ; i < sz(leaves); ++i)
            res = max(res + 1, leaves[i]);
        leaves.clear();
        return res;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n - 1 ; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << solve() << '\n';
    return 0;
}
