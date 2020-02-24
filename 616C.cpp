#include<bits/stdc++.h>
using namespace std;
const int maxn = 300500;
const int mod = 1e9 + 7;
pair < int, int > a[maxn];
int child[maxn];
bool vis[maxn];

struct DSU{
    int parent[maxn];
    int sz[maxn];
    int ans[maxn];
    int forced[maxn];
    bool all[maxn];
    int find_set(int v) {
        assert(v < maxn);
        if (v == parent[v])  return v;
        return parent[v] = find_set(parent[v]);
    }
    void make_set(int v) {
        parent[v] = v;
        sz[v] = 1;
        forced[v] = -1;
        all[v] = false;
    }
    void init(int n){
        assert(n < maxn);
        for(int i = 0 ; i < n ; ++i)
            make_set(i);
    }
    void union_sets(int a, int b) {
        assert(a < maxn);
        assert(b < maxn);
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (sz[a] < sz[b])
                swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            forced[a] = max(forced[a], forced[b]);
            all[a] |= all[b];
        }
    }
}dsu;

int get(int u){
    if(!vis[u]) return 0;
    int idx = dsu.find_set(u);
    if(dsu.all[idx]){
        int res = dsu.sz[idx];
        if(~child[u]) res += dsu.sz[dsu.find_set(child[u])];
        return res;
    }
    if(dsu.forced[idx] == 1) return dsu.sz[idx];
    if(dsu.forced[idx] == 2){
        if(~child[u]) return dsu.sz[dsu.find_set(child[u])];
        return 0;
    }
    assert(~child[u]);
    if(dsu.sz[idx] < dsu.sz[dsu.find_set(child[u])]) return dsu.sz[idx];
    return dsu.sz[dsu.find_set(child[u])];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    dsu.init(k);
    for(int i = 0 ; i < k ; ++i) child[i] = -1;
    for(int i = 0 ; i < n ; ++i) a[i] = {-1, -1};
    string s;
    cin >> s;
    for(int i = 0 ; i < k ; ++i){
        int l;
        cin >> l;
        for(int j = 0 ; j < l ; ++j){
            int x;
            cin >> x;
            --x;
            if(~a[x].first) a[x].second = i;
            else a[x].first = i;
        }
    }
    int ans = 0;
    for(int i = 0 ; i < 4 ; ++i)
        if(~a[i].second){
            int u = a[i].first;
            int v = a[i].second;
            ans -= get(u);
            ans -= get(v);
            if(s[i]){
                dsu.all[dsu.find_set(u)] = true;
                ans += dsu.sz[dsu.find_set(u)] + dsu.sz[dsu.find_set(v)];
                if(~child[u]) dsu.union_sets(child[u], v);
                if(~child[v]) dsu.union_sets(child[v], u);
                child[u] = v;
                child[v] = u;
                cout << ans << '\n';
                vis[u] = vis[v] = true;
                continue;
            }
            if(~child[u]) dsu.union_sets(child[u], v);
            if(~child[v]) dsu.union_sets(child[v], u);
            if(dsu.all[dsu.find_set(u)] || dsu.all[dsu.find_set(v)]) ans += dsu.sz[dsu.find_set(u)] + dsu.sz[dsu.find_set(v)];
            else{
                if(dsu.forced[dsu.find_set(u)] == 1 || dsu.forced[dsu.find_set(v)] == 2) ans += dsu.sz[dsu.find_set(u)];
                else if(dsu.forced[dsu.find_set(v)] == 1 || dsu.forced[dsu.find_set(u)] == 2) ans += dsu.sz[dsu.find_set(v)];
                else if(dsu.sz[dsu.find_set(u)] < dsu.sz[dsu.find_set(v)] ) ans += dsu.sz[dsu.find_set(u)];
                else ans += dsu.sz[dsu.find_set(v)];
                cout << ans << '\n';
            }
            vis[u] = vis[v] = true;
        }else{
            if(a[i].first == -1){
                cout << ans << '\n';
                continue;
            }
            int u = a[i].first;
            ans -= get(u);
            if(s[i] == '1'){
                dsu.forced[dsu.find_set(u)] = 2;
                if(~child[u]) ans += dsu.sz[dsu.find_set(child[u])];
            }else{
                dsu.forced[dsu.find_set(u)] = 1;
                ans += dsu.sz[dsu.forced[dsu.find_set(u)]];
            }
            cout << ans << '\n';
            vis[u] = true;
        }
    return 0;
}
