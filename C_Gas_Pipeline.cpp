#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
int dp[2][maxn], n, a, b;
string s;

int solve(int i, bool prv){
    if(i == sz(s) - 1){
        if(prv) return 2 * a + 3 * b;
        return a + 2 * b;
    }
    int &ret = dp[prv][i];
    if(~ret) return ret;
    if(s[i] == '1'){
        if(prv) ret = 2 * b + solve(i + 1, true);
        else ret = 2 * b + a + solve(i + 1, true);
    }else{
        if(prv){
            ret = 2 * b + solve(i + 1, true);
            ret = min(ret, 2 * b + a + solve(i + 1, false));
        }else{
            ret = b + solve(i + 1, false);
            ret = min(ret, 3 * b + a + solve(i + 1, true));
        }
    }
    ret += a;
    return ret ;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> a >> b;
        cin >> s;
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < 2 ; ++j)
                dp[j][i] = -1;
        cout << a + b + solve(1, 0) << '\n';
    }
    return 0;
}