#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1000500;
const int mod = 1e9 + 7;
int n, k;
int dp[10 * maxn][2];

int solve(int rem, int turn){
    if(rem == 0) return turn;
    //if(~dp[rem][turn]) return dp[rem][turn];
    int ans;
    if(!turn){
        ans = 0;
        if(rem >= k) ans = max(ans, solve(rem - k, 1 - turn));
        if(rem >= 2) ans = max(ans, solve(rem - 2, 1 - turn));
        ans = max(ans, solve(rem - 1, 1 - turn));
    }else{
        ans = 1;
        if(rem >= k) ans = min(ans, solve(rem - k, 1 - turn));
        if(rem >= 2) ans = min(ans, solve(rem - 2, 1 - turn));
        ans = min(ans, solve(rem - 1, 1 - turn));
    }
    return dp[rem][turn] = ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    /*for(k = 3 ; k <= 15 ; ++k){
        string s = "";
        for(n = 1 ; n <= 20 ; ++n)
            s += ;
        cout << k << " => " << s << '\n';
    }*/
    while(t--){
        cin >> n >> k;
        if(!n){
            cout << "Bob\n";
            continue;
        }
        if(k % 3 != 0){
            if(n % 3) cout << "Alice\n";
            else cout << "Bob\n";
        }else{
            int d = k / 3 - 1;
            int dv = d * 3 + 4;
            n %= dv;
            if(n >= dv - 3) cout << "Alice\n";
            else{
                if(n % 3) cout << "Alice\n";
            else cout << "Bob\n";
            }
        }
    }
    return 0;
}


