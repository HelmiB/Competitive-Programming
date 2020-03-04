#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 501;
const int mod = 1e9 + 7;

struct SparseTable2D{
    long long t[maxn][maxn], dp[maxn][maxn][9][9], lg[maxn];
    SparseTable2D(){
        lg[1] = 0 ;
        for(int i = 2 ; i < maxn; ++i)
            lg[i] = 1 + lg[i/2];
    }
    long long op(long long a, long long b){
        // define operation here : gcd, min, max ... (careful only commutative operations)
        return max(a, b);
    }
    void build(int n, int m){
        assert(n < maxn && m < maxn);
        for (int k = 0; (1 << k) <= n; k++)
            for (int l = 0; (1 << l) <= m; l++)
                for (int i = 1; i + (1 << k) - 1 <= n; i++)
                    for (int j = 1; j + (1 << l) - 1 <= m; j++){
                        if (!k && !l) dp[i][j][k][l] = t[i][j];
                        else if (k == 0)
                            dp[i][j][k][l] = op(dp[i][j][k][l - 1],
                                                dp[i][j + (1 << (l - 1))][k][l - 1]);
                        else if (l == 0)
                            dp[i][j][k][l] = op(dp[i][j][k - 1][l],
                                                dp[i + (1 << (k - 1))][j][k - 1][l]);
                        else dp[i][j][k][l] = op(op(dp[i][j][k - 1][l - 1],
                                                    dp[i + (1 << (k - 1))][j][k - 1][l - 1]),
                                                op(dp[i][j + (1 << (l - 1))][k - 1][l - 1],
                                                    dp[i + (1 << (k - 1))][j + (1 << (l - 1))]
                                                                        [k - 1][l - 1]));
                    }
    }
    long long query(int x0, int y0, int x1, int y1){
        if(x0 > x1 || y0 > y1) return 0; // or inf, depends on op
        int k = lg[x1 - x0 + 1];
        int l = lg[y1 - y0 + 1];
        return op(op(dp[x0][y0][k][l], dp[x1 - (1 << k) + 1][y0][k][l]),op(
                    dp[x0][y1 - (1 << l) + 1][k][l],
                    dp[x1 - (1 << k) + 1][y1 - (1 << l) + 1][k][l]));
    }
}spt2d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            spt2d.t[i + 1][j + 1] = 1e9 + 1;
    while(q--){
        int x, y, t;
        cin >> x >> y >> t;
        spt2d.t[x][y] = t;
    }
    spt2d.build(n, m);
    int ans = 1e9 + 1;
    for(int i = 0 ; i + k - 1 < n ; ++i)
        for(int j = 0 ; j + k - 1 < m ; ++j)
            ans = min(ans, (int)spt2d.query(i + 1, j + 1, i + k, j + k));
    cout << (ans == 1e9 + 1 ? -1:ans) << '\n';
    return 0;
}
