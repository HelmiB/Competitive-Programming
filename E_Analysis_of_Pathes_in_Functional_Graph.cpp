#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
bool vis[maxn];

struct SparseTable{
    long long t[2][maxn],dp[maxn][41], lg[maxn], sum[maxn][41], mn[maxn][41];
    SparseTable(){
        lg[1] = 0 ;
        for(int i = 2 ; i < maxn; ++i)
            lg[i] = 1 + lg[i/2];
    }
    void build(int n){
        assert(n < maxn);
        for(int i = 0 ; i < n ; ++i){
            dp[i][0] = t[0][i];
            sum[i][0] = mn[i][0] = t[1][i];
        }

        for(int j = 1 ; j <= 40 ; ++j)
            for(int i = 0 ; i < n ; ++i){
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
                sum[i][j] = sum[i][j - 1] + sum[dp[i][j - 1]][j - 1];
                mn[i][j] = min(mn[i][j - 1], mn[dp[i][j - 1]][j - 1]);
            }
    }
}spt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    long long k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; ++i) cin >> spt.t[0][i];
    for(int i = 0 ; i < n ; ++i) cin >> spt.t[1][i];
    spt.build(n);
    for(int i = 0 ; i < n ; ++i){
        long long mini = 1e9, sm = 0;
        long long ad = k;
        int cur = i;
        for(int j = 40 ; j >= 0; --j)
            if((1ll << j) <= ad){
                ad -= (1ll << j);
                mini = min(mini, spt.mn[cur][j]);
                sm += spt.sum[cur][j];
                cur = spt.dp[cur][j];
            }
        cout << sm << ' ' << mini << '\n';
    }
    return 0;
}