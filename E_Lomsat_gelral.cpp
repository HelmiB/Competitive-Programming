#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < int > g[maxn];
set < pair < int, long long  > > res[maxn];
int mx[maxn], col[maxn], idx[maxn];
long long cnt[maxn], ans[maxn];
int cur;

void solve(int u = 0, int p = -1){
    int id = -1, bst = -1;
    for(auto v : g[u])
        if(v != p){
            solve(v, u);
            if(sz(res[idx[v]]) > bst) id = idx[v], bst = sz(res[idx[v]]);
        }
    if(id == -1) id = cur++;
    if(res[id].upper_bound(make_pair(col[u], -1)) != res[id].end()){
        auto it = *res[id].upper_bound(make_pair(col[u], -1));
        if(it.first != col[u]){
            res[id].insert({col[u], 1});
            if(mx[id] == 1) cnt[id] += col[u];
            else if(!mx[id]){
                mx[id] = 1;
                cnt[id] = col[u];
            }
        }else{
            res[id].erase(it);
            it.second++;
            res[id].insert(it);
            if(mx[id] == it.second) cnt[id] += col[u];
            else if(mx[id] < it.second){
                mx[id] = it.second;
                cnt[id] = col[u];
            }
        }
    }else{
        res[id].insert({col[u], 1});
        if(mx[id] == 1) cnt[id] += col[u];        else if(!mx[id]){
            mx[id] = 1;
            cnt[id] = col[u];
        }
    }
    for(auto v : g[u])
        if(v != p && idx[v] != id)
            for(auto x : res[idx[v]]){
                if(res[id].upper_bound(make_pair(x.first, -1)) != res[id].end()){
                    auto it = *res[id].upper_bound(make_pair(x.first, -1));
                    if(it.first != x.first){
                        res[id].insert(x);
                        if(mx[id] == x.second) cnt[id] += x.first;
                        else if(mx[id] < x.second){
                            mx[id] = x.second;
                            cnt[id] = x.first;
                        }
                    }else{
                        res[id].erase(it);
                        it.second += x.second ;
                        res[id].insert(it);
                        if(mx[id] == it.second) cnt[id] += it.first;
                        else if(mx[id] < it.second){
                            mx[id] = it.second;
                            cnt[id] = it.first;
                        }
                    }
                }else{
                    res[id].insert(x);
                    if(mx[id] == x.second) cnt[id] += x.first;
                        else if(mx[id] < x.second){
                            mx[id] = x.second;
                            cnt[id] = x.first;
                        }
                }
            }
    ans[u] = cnt[id];
    idx[u] = id;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> col[i];
    for(int i = 0 ; i < n - 1 ; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    solve();
    for(int i = 0 ; i < n ; ++i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}
