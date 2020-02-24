#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
const int INF = 1000000;
int T, N;
int dp[101][(1 << 5)];
string S;
int solve(int pos, int mask){
    if(pos == N){
        if(mask == 0)return 0;
        return -INF;
    }
    int &ret = dp[pos][mask];
    if(ret != -1)return ret; 
    ret = -INF;
    if(S[pos] == 'i'){
        if(((1 << 0) & mask) == 0)ret = max(ret, solve(pos + 1, mask ^ (1 << 0)));
        if(((1 << 1) & mask) == 0)ret = max(ret, solve(pos + 1, mask ^ (1 << 1)));
    }
    if(S[pos] == 'I'){01
        if(((1 << 2) & mask) == 0)ret = max(ret, solve(pos + 1, mask ^ (1 << 2)));
        if(((1 << 3) & mask) == 0)ret = max(ret, solve(pos + 1, mask ^ (1 << 3)));
    }
    if(S[pos] == 'o'){
        if(((1 << 0) & mask))ret = max(ret, solve(pos + 1, mask ^ (1 << 0)));
        if(((1 << 2) & mask))ret = max(ret, solve(pos + 1, mask ^ (1 << 2)));
    }
    if(S[pos] == 'O'){
        if(((1 << 1) & mask))ret = max(ret, solve(pos + 1, mask ^ (1 << 1)));
        if(((1 << 3) & mask))ret = max(ret, 1 + solve(pos + 1, mask ^ (1 << 3)));
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> S;
        N = S.size();
        memset(dp, -1, sizeof dp);
        cout << "Case #" << t << ": " << solve(0, 0) << '\n';
    }
    return 0;
}
