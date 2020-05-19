#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < int > g[maxn];
bool cat[maxn];
int n, x;

int solve(int u, int p = -1){
    if(cat[u]) return 1;
    int ans = 0;
    for(auto v : g[u])
        if(v != p)
            ans += solve(v, u);
    if(u != x) ans = min(ans, 1);
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> x;
    --x;
    for(int i = 0 ; i < n - 1 ; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int k;
    cin >> k;
    for(int i = 0 ; i < k ; ++i){
        int u;
        cin >> u;
        cat[u - 1] = true;
    }
    cout << solve(x) << '\n';
    return 0;
}