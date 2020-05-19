#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
bool vis[501][501];
int a[501][501];
priority_queue < pair < int , pair < int, int > > > pq;
long long ans;
int n, m;

bool valid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j];
}

void solve(int i, int j){
    if(vis[i][j]) return;
    vis[i][j] = true;
    for(int k = 0 ; k < 4 ; ++k){
        int x = i + dx[k];
        int y = j + dy[k];
        if(!valid(x, y)) continue;
        if(a[x][y] <= a[i][j]){
            ans += a[i][j] - a[x][y];
            a[x][y] = a[i][j];
            solve(x, y);
        }else pq.push({-a[x][y], {x, y}});
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j){
            cin >> a[i][j];
            if(!i || !j || i == n - 1 || j == m - 1)
                pq.push({-a[i][j], {i, j}});
        }    
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        solve(u.second.first, u.second.second);
    }
    cout << ans << '\n';
    return 0;
}