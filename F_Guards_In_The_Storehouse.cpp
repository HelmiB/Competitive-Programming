#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int n, m;
char grid[255][255];
char tmp[255][255];
int dp[255][(1 << 15)][2][2];
 
int solve(int row = 0, int col = 0, int msk = 0, bool f1 = false, bool f2 = false){
    if(row == n) return 1;
    if(col == m) return solve(row + 1, 0, msk, f1, false);
    int &ret = dp[row * m + col][msk][f1][f2];
    if(~ret)return ret;
    ret = 0;
    if(grid[row][col] == '.'){
      if((msk & (1 << col)) || f2)
        ret = solve(row, col + 1, msk, f1, f2);
      ret += solve(row, col + 1, msk | (1 << col), f1, true);
      if(ret >= mod)  ret -= mod;
      if((msk & (1 << col)) == 0 && !f2 && !f1)
        ret += solve(row, col + 1, msk, true, false);
      if(ret >= mod) ret -= mod;
    } else ret = solve(row, col + 1, msk &~(1 << col), f1, false);
    return ret;
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0 ; j < m ; ++j)
            cin >> grid[i][j];
    if(n < m){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                tmp[j][n - i - 1] = grid[i][j];
        swap(n, m);
        for(int i = 0; i < n; i++) reverse(tmp[i], tmp[i] + m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                grid[i][j] = tmp[i][j];
    }
    memset(dp, -1, sizeof dp);
    cout << solve() << '\n';
    return 0;
}