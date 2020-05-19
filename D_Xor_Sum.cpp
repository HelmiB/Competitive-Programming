#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int dp[70][2][2][2]; // dp[bit][carry][(a + b) < N][(a ^ b) < N]
int n;

int add(int x, int y) { return (x + y + mod) % mod; }

int solve(int bit = 61, bool carry = false, bool sm = false, bool xr = false){
    if(bit == -1) return 1 - carry;
    int &ret = dp[bit][carry][sm][xr];
    if(~ret) return ret;
    ret = 0;
    bool state = (((1ll << bit) & n) > 0);
    for(int a = 0 ; a < 2 ; ++a)
        for(int b = a; b < 2; ++b){
            int ans = 0;
            bool axorb = (a ^ b);
            int ad = a + b;
            if(!xr && (axorb > state)) continue;
            if(!ad){
                if(carry) continue;
                ret = add(ret,
                    solve(bit - 1, false, sm | state, xr | (axorb < state)));
                if(sm || state) 
                ret = add(ret,
                    solve(bit - 1, true, sm, xr | (axorb < state)));
            }else if(ad == 1){
                if(carry){
                    ret = add(ret,
                        solve(bit - 1, true, sm | state, xr | (axorb < state)));   
                }else{
                    if(!sm && !state) continue;
                    ret = add(ret,
                    solve(bit - 1, false, sm, xr | (axorb < state)));
                }
            }else if(ad == 2){
                if(!carry) continue;
                ret = add(ret,
                    solve(bit - 1, false, sm | state, xr | (axorb < state)));
                if(sm || state) 
                ret = add(ret,
                    solve(bit - 1, true, sm, xr | (axorb < state)));
            } 
        }
    return ret;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;  
    memset(dp, -1, sizeof dp);
    cout << solve() << '\n';
    return 0;
}