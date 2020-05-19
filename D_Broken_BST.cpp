#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int g[maxn][2], a[maxn];
bool root[maxn];
set < int > cool;

void solve(int u, int L = 1e9 + 1, int R = -1){
    if(u == -1) return ;
    if(a[u] < L && a[u] >= R) cool.insert(a[u]);
    solve(g[u][0], min(L, a[u]), R);
    solve(g[u][1], L, max(a[u], R));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> a[i];
        for(int j = 0 ; j < 2 ; ++j){
            cin >> g[i][j];
            if(g[i][j] > 0) root[g[i][j]] = true;
        }
    }
    for(int i = 1 ; i <= n ; ++i)
        if(!root[i]){
            solve(i);
            break;
        }
    int ans = 0;
    for(int i = 1 ; i <= n ; ++i) ans += (cool.find(a[i]) == cool.end());
    cout << ans << '\n';
    return 0;
}