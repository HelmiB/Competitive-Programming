#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
int a[maxn], b[maxn], cost[maxn];
vector < pair < int, int > > g[maxn];

void no(){
    cout << "NO\n";
    exit(0);
}
void solve(int u, int p){
    cost[u] = b[u] - a[u];
    for(auto v : g[u])
        if(v.first != p){
            solve(v.first, u);
            if(cost[v.first] >= 0) cost[u] += cost[v.first];
            else {
                if(cost[v.first] < -2e18 / v.second) no();
                cost[u] += cost[v.first] * v.second;

            }
            if(cost[u] > 2e18) cost[u] = 2e18;
            if(cost[u] < -2e18) no();
        }
    if(cost[u] > 2e18) cost[u] = 2e18;
    if(cost[u] < -2e18) no();
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> b[i];
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    for(int i = 1 ; i < n ; ++i){
        int par, k;
        cin >> par >> k;
        --par;
        g[par].push_back({i, k});
    }
    solve(0, -1);
    cout << (cost[0] >= 0 ? "YES":"NO") << '\n';
    return 0;
}