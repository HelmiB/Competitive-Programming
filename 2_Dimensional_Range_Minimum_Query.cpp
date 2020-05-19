#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1050;
const int mod = 1e9 + 7;

struct SparseTable2D{ // this structure is 1-based !
    int t[maxn][maxn], dp[11][11][maxn][maxn], lg[maxn];
    SparseTable2D(){
        lg[1] = 0 ;
        for(int i = 2 ; i < maxn; ++i)
            lg[i] = 1 + lg[i/2];
    }
    int op(int a, int b){
        return min(a, b);
    }
    void build(int n, int m){
        assert(n < maxn && m < maxn);
        for (int k = 0; (1 << k) <= n; k++)
            for (int l = 0; (1 << l) <= m; l++)
                for (int i = 1; i + (1 << k) - 1 <= n; i++)
                    for (int j = 1; j + (1 << l) - 1 <= m; j++){
                        if (!k && !l) dp[k][l][i][j] = t[i][j];
                        else if (k == 0)
                            dp[k][l][i][j] = op(dp[k][l - 1][i][j],
                                                dp[k][l - 1][i][j + (1 << (l - 1))]);
                        else if (l == 0)
                            dp[k][l][i][j] = op(dp[k - 1][l][i][j],
                                                dp[k - 1][l][i + (1 << (k - 1))][j]);
                        else dp[k][l][i][j] = op(op(dp[k - 1][l - 1][i][j],
                                                    dp[k - 1][l - 1][i + (1 << (k - 1))][j]),
                                                op(dp[k - 1][l - 1][i][j + (1 << (l - 1))],
                                                    dp[k - 1][l - 1][i + (1 << (k - 1))][j + (1 << (l - 1))]));
                    }
    }
    int query(int x0, int y0, int x1, int y1){
        if(x0 > x1 || y0 > y1) return 1e9; // or inf, depends on op
        int k = lg[x1 - x0 + 1];
        int l = lg[y1 - y0 + 1];
        return op(op(dp[k][l][x0][y0], dp[k][l][x1 - (1 << k) + 1][y0]),op(
                    dp[k][l][x0][y1 - (1 << l) + 1],
                    dp[k][l][x1 - (1 << k) + 1][y1 - (1 << l) + 1]));
    }
}spt2d;

void init(std::vector<std::vector<int>> arr){
    for(int i = 0 ; i < sz(arr); ++i)
        for(int j = 0 ; j < sz(arr) ; ++j)
            spt2d.t[i + 1][j + 1] = arr[i][j];
    spt2d.build(sz(arr), sz(arr));
}

int query(int a, int b, int c, int d){
    return spt2d.query(a + 1, c + 1, b + 1, d + 1);
}

int main(){
    return 0;
}