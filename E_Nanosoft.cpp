#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
string s = "RGBY";
int sz[501][501][252], c[501][501][4]; 
char g[501][501];


//res((a, b), (c, d)) = sum[c, d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1]
bool good(int i, int j, int len){
    int a = i - len + 1, b = j - len + 1, cc = i, d = j;
    if(c[cc][d][0] - c[a - 1][d][0] - c[cc][b - 1][0] + c[a - 1][b - 1][0] != len * len) return false;
    a = i - len + 1, b = j + 1, cc = i, d = j + len;
    if(c[cc][d][1] - c[a - 1][d][1] - c[cc][b - 1][1] + c[a - 1][b - 1][1] != len * len) return false;
    a = i + 1, b = j + 1, cc = i + len , d = j + len;
    if(c[cc][d][2] - c[a - 1][d][2] - c[cc][b - 1][2] + c[a - 1][b - 1][2] != len * len) return false;
    a = i + 1 , b = j - len + 1, cc = i + len, d = j;
    if(c[cc][d][3] - c[a - 1][d][3] - c[cc][b - 1][3] + c[a - 1][b - 1][3] != len * len) return false;
    return true;
}

bool can(int l0, int r0, int l1, int r1, int mid){
    if(l0 > l1 || r0 > r1) return false;
    return sz[l1][r1][mid] - sz[l0 - 1][r1][mid] - sz[l1][r0 - 1][mid] + sz[l0 - 1][r0 - 1][mid] > 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
            cin >> g[i][j];
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
            for(int k = 0 ; k < 4 ; ++k)
                c[i][j][k] = (g[i][j] == s[k]) + c[i - 1][j][k] + c[i][j - 1][k] - c[i - 1][j - 1][k];
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j){
            bool can = true;
            int l = min(i, j), r = min(n - i, m - j);
            for(int len = 1 ; len <= min(l, r) && can; ++len)
                if(good(i, j, len)) sz[i - len + 1][j - len + 1][len] = 1;
                else can = false;
        }
    for(int j = 1 ; j <= m ; ++j)
        for(int i = 1 ; i <= n ; ++i)
            for(int k = 1 ; k <= min(n / 2, m / 2) ; ++k)
                sz[i][j][k] += sz[i - 1][j][k];
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
            for(int k = 1 ; k <= min(n / 2, m / 2) ; ++k)
                sz[i][j][k] += sz[i][j - 1][k];
    /*for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j)
            cout << sz[i][j][1] << ' ';
        cout << '\n';
    }*/
    for(int i = 0 ; i < q ; ++i){
        int l0, r0, l1, r1;
        cin >> l0 >> r0 >> l1 >> r1;
        int lo = 1, hi = min(n / 2, m / 2);
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(can(l0, r0, l1 - 2 * mid + 1, r1 - 2 * mid + 1, mid)) lo = mid + 1;
            else hi = mid - 1;
        }
        cout << 4 * (lo - 1) * (lo - 1) << '\n';
    }
    return 0;
}
