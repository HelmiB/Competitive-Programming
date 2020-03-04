#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
pair < long long, long long > dp[100][150][250][2];
long long pw[250];
int dg[250];
int vis[100][150][250][2];
string s;
int idx;

long long add(long long x, long long y) { 
    x += y;
    if(x >= mod) x -= mod;
    if(x < 0) x += mod;
    return x;
}
long long mul(long long x, long long y) { return (add(x, mod) * add(y, mod)) % mod; }

int dig(int X){
    string s = to_string(X);
    return sz(s);
}


pair < long long, long long > solve(int i = 0, int xr = 0, int fx = sz(s) * 3, bool gr = false){
    if(fx < 0) return {0, 0};
    if(i == sz(s)) return {0, !fx};
    pair < long long, long long > &ret = dp[i][xr][fx][gr];
    if(vis[i][xr][fx][gr] == idx) return ret;
    vis[i][xr][fx][gr] = idx;
    ret = {0, 0};
    int d = s[i] - '0';
    for(int x = 0 ; x <= 9 ; ++x)
        if(x <= d || gr){
            int xr1 = (x * x) ^ xr;
            if(fx < dg[xr1]) continue;
            pair < long long, long long > sm = solve(i + 1, xr1, fx - dg[xr1], gr | (x < d));
            ret.first = add(ret.first, sm.first);
            ret.first = add(ret.first, mul(mul(xr1, pw[fx - dg[xr1]]), sm.second));
            ret.second = add(ret.second, sm.second);
        }
    return ret;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("legendary.in", "r", stdin);
    int T;
    cin >> T;
    pw[0] = dg[0] = 1LL;
    for(int i = 1 ; i < 250 ; ++i){
        dg[i] = dig(i);
        pw[i] = mul(pw[i - 1], 10);
    }
    while(T--){
        cin >> s;
        idx++;
        long long ans = 0;
        for(int i = 0 ; i <= sz(s) * 3; ++i) ans = add(ans, solve(0, 0, i, false).first);
        
        cout << ans << '\n';
    }
    return 0;
}
