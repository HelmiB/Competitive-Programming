#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[maxn], b[maxn];
bool vis[maxn];

int dfs(int u, int * a){
    if(vis[u]) return 0;
    vis[u] = true;
    return 1 + dfs(a[u], a);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    int tc = 1;
    while(cin >> n >> m){
        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        vector < int > cyc;
        memset(vis, 0, n * sizeof vis[0]);
        for(int i = 0 ; i < n ; ++i)
            if(!vis[i])
                cyc.push_back(dfs(i, a));
        for(int i = 0 ; i < m ; ++i) cin >> b[i];
        map < int, int > occ;
        memset(vis, 0, m * sizeof vis[0]);
        for(int i = 0 ; i < m ; ++i)
            if(!vis[i])
                occ[dfs(i, b)]++;
        long long ans = 1LL;
        for(auto l : cyc){
            long long ad = 0;
            for(int i = 1 ; i * i <= l ; ++i)
                if(l % i == 0){
                    ad = (ad + (i * 1LL * occ[i]) % mod) % mod;
                    if(i != l / i)
                        ad = (ad + ((l / i) * 1LL * occ[l / i]) % mod) % mod;
                }
            ans = (ans * ad) % mod;
        }
        cout << "Case #" << tc << ": " << ans << '\n';
        tc++;            
    }

    return 0;
}
