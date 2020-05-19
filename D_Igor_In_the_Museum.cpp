#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
bool vis[1010][1010];
int id[1010][1010];
int ans[1010 * 1010];
char a[1010][1010];
int n, m, cur;

bool valid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y];
}

int solve(int x, int y){
    if(a[x][y] == '*') return 1;
    vis[x][y] = true;
    id[x][y] = cur;
    int ans = 0;
    for(int k = 0 ; k < 4 ; ++k){
        int nx = x + dx[k], ny = y + dy[k];
        if(!valid(nx, ny)) continue;
        ans += solve(nx, ny);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k;
    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; ++i)     
        for(int j = 0 ; j < m ; ++j)
            cin >> a[i][j];
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            if(a[i][j] == '.' && !vis[i][j]){
                cur++;
                ans[cur] = solve(i, j);
            }
    while(k--){
        int x, y;
        cin >> x >> y;
        --x; --y;
        cout << ans[id[x][y]] << '\n';
    }
    return 0;
}
