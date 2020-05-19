#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < long double > dp[1 << 18];
bool vis[1 << 18];
long double a[20][20];
int n;

vector < long double > solve(int mask){
    if(__builtin_popcount(mask) == 1){
        vector < long double > v(n, 0);
        for(int i = 0 ; i < n ; ++i)
            if((1 << i) & mask){
                v[i] = 1;
                break;
            }
        return v;
    }
    auto &ret = dp[mask];
    if(vis[mask]) return ret;
    vis[mask] = true;
    int tot = __builtin_popcount(mask);
    tot *= (tot - 1);
    tot /= 2;
    vector < int > in;
    for(int i = 0 ; i < n ; ++i)
        if((1 << i) & mask)
            in.push_back(i);
    for(int i = 0 ; i < sz(in); ++i){
        long double acc = 0;
        for(int j = 0 ; j < sz(in); ++j)
            acc += a[in[j]][in[i]];
        auto op = solve(mask ^ (1 << in[i]));
        for(int k = 0 ; k < sz(in) ; ++k)
            ret[in[k]] += acc * op[in[k]] / tot;
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
            cin >> a[i][j];
    for(int i = 0 ; i < (1 << n); ++i) dp[i].resize(n, 0);
    auto ans = solve((1 << n) - 1);
    cout << fixed << setprecision(6);
    for(auto e : ans) cout << e << ' ';
    cout << '\n';
    return 0;
}