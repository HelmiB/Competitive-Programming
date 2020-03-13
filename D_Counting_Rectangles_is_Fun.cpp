#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int sm[45][45], sz[45][45][45][45];
int n, m, q;

int get(int a, int b, int c, int d){
    return sm[c][d] - sm[c][b - 1] - sm[a - 1][d] + sm[a - 1][b - 1];
}

int solve(int a, int b, int c, int d, int h, int w){
    return sz[c][d][h][w] - sz[a - 1][d][h][w] - sz[c][b - 1][h][w] + sz[a - 1][b - 1][h][w];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j){
            char c;
            cin >> c;
            sm[i][j] = (c == '0') + sm[i - 1][j] + sm[i][j - 1] - sm[i - 1][j - 1];
        }
    for(int i = 1 ; i <= n ; ++i)
        for(int j = 1 ; j <= m ; ++j)
            for(int h = 1 ; i + h - 1 <= n ; ++h)
                for(int w = 1 ; j + w - 1 <= m ; ++w)
                    sz[i][j][h][w] = (get(i, j, i + h - 1, j + w - 1) == h * w) + sz[i - 1][j][h][w] + sz[i][j - 1][h][w] - sz[i - 1][j - 1][h][w];
    while(q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        for(int h = 1 ; h <= c - a + 1 ; ++h)
            for(int w = 1 ; w <= d - b + 1; ++w)
                ans += solve(a, b, c - h + 1, d - w + 1, h, w);
        cout << ans << '\n';
    }       
    return 0;
}
