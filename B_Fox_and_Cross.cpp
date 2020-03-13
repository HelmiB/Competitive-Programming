#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
bool vis[101][101];
char mat[101][101];

void NO(){
    cout << "NO\n";
    exit(0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
            cin >> mat[i][j];
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
            if(mat[i][j] == '#' && !vis[i][j]){
                if(!j || i >= n - 2 || j == n - 1) NO();
                if(mat[i + 1][j] != '#' || mat[i + 1][j + 1] != '#' || mat[i + 1][j - 1] != '#' || mat[i + 2][j] != '#') NO();
                if(vis[i + 1][j] || vis[i + 1][j + 1] || vis[i + 1][j - 1] || vis[i + 2][j]) NO();
                vis[i + 1][j] = vis[i + 1][j + 1] = vis[i + 1][j - 1] = vis[i + 2][j] = true;
            }    
    cout << "YES\n";
    return 0;
}
