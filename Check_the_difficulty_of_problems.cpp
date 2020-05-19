#include<iostream>
#include<iomanip>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int n, m, t;
long double dp[1010][31][31][2], p[32][1010];
int vis[1010][31][31][2], iter;


long double solve(int team, int prb, int solved, bool winner){
    if(team == t) return winner;
    if(prb == m){
        if(!solved) return 0;
        return solve(team + 1, 0, 0, winner | (solved >= n));
    }
    long double &ret = dp[team][prb][solved][winner];
    if(vis[team][prb][solved][winner] == iter) return ret;
    vis[team][prb][solved][winner] = iter;
    return ret = p[prb][team] * solve(team, prb + 1, solved + 1, winner)
                + (1.0 - p[prb][team]) * solve(team, prb + 1, solved, winner);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(cin >> m >> t >> n){
        if(m + t + n == 0) break;
        iter++;
        for(int i = 0 ; i < t ; ++i)
            for(int j = 0 ; j < m ; ++j)
                cin >> p[j][i];
        cout << fixed << setprecision(3) << solve(0, 0, 0, 0) << '\n';
    }

    return 0;
}