#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int in[maxn], rs[maxn];
vector < int > g[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; ++i){
        int u, v;
        cin >> u >> v;
        --u; --v;
        in[u]++;
        g[v].push_back(u);
    }
    priority_queue < int > pq;
    for(int i = 0 ; i < n ; ++i)
        if(!in[i])
            pq.push(i);
    int cur = n;
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        rs[u] = cur--;
        for(auto v : g[u]){
            in[v]--;
            if(!in[v]) pq.push(v);
        }
    }
    for(int i = 0 ; i < n ; ++i) cout << rs[i] << ' ';
    cout << '\n';
    return 0;
}