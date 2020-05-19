#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int id[1010][1010];
int sz[1010 * 1010];
bool vis[1010][1010];
char g[1010][1010], res[1010][1010];
int cur;
int n, m;

bool valid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m && g[i][j] == '.';
}

void solve(int i, int j){
    vis[i][j] = true;
    id[i][j] = cur;
    sz[cur]++;
    for(int k = 0 ; k < 4 ; ++k){
        int x = i + dx[k];
        int y = j + dy[k];
        if(!valid(x, y) || vis[x][y]) continue;
        solve(x, y);
    }
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            cin >> g[i][j], res[i][j] = g[i][j];
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            if(g[i][j] != '*' && !vis[i][j]){
                cur++;
                solve(i, j);
            }
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            if(g[i][j] == '*'){
                set < int > ids;
                for(int k = 0 ; k < 4 ; ++k)
                    if(valid(i + dx[k], j + dy[k]))
                        ids.insert(id[i + dx[k]][j + dy[k]]);
                int sm = 1;
                for(auto x : ids) sm += sz[x];
                sm %= 10;
                res[i][j] = (char)('0' + sm);
            }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j)
            cout << res[i][j];
        cout << '\n';
    }
    return 0;
}
