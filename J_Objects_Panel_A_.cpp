#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < int > g[maxn];
bool op[maxn];

void solve(int u, int lvl = 0){
    for(int i = 0 ; i < lvl ; ++i) cout << "  ";
    if(!op[u] && !sz(g[u])){
        if(u) cout << "  object" << u << '\n';
        else cout << "  project" << '\n';
        return; 
    }
    if(op[u]){
        if(u) cout << "+ object" << u << '\n';
        else cout << "+ project" << '\n';
        return;
    }
    if(u) cout << "- object" << u << '\n';
    else cout << "- project" << '\n';
    for(auto v : g[u])
        solve(v, lvl + 1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i <= n ; ++i){
        char c;
        cin >> c;
        op[i] = c == '+';
        int k;
        cin >> k;
        for(int j = 0 ; j < k ; ++j){
            int p;
            cin >> p;
            g[i].push_back(p);
        }
    }
    solve(0);
    return 0;
}