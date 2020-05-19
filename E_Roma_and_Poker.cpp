#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
bool dp[1010][2010], vis[1010][2010];
string s;
int k;

bool good(int x){
    return !x || (x == 2 * k);
}

bool solve(int i, int rem){
    if(i == sz(s)) return good(rem);
    if(good(rem)) return false;
    bool &ret = dp[i][rem];
    if(vis[i][rem]) return ret;
    vis[i][rem] = true;
    if(s[i] == '?') return ret = solve(i + 1, rem + 1) | solve(i + 1, rem - 1) | solve(i + 1, rem);
    if(s[i] == 'W') return ret = solve(i + 1, rem + 1);
    if(s[i] == 'L') return ret = solve(i + 1, rem - 1);
    if(s[i] == 'D') return ret = solve(i + 1, rem);
    return ret;
}

void track(int i, int rem){
    if(i == sz(s)){
        cout << '\n';
        return;
    }
    if(s[i] == '?'){
        if(solve(i + 1, rem + 1)){
            cout << 'W';
            track(i + 1, rem + 1);
            return;
        }
        if(solve(i + 1, rem - 1)){
            cout << 'L';
            track(i + 1, rem - 1);
            return;
        }
        cout << 'D';
        track(i + 1, rem);
        return;
    }
    if(s[i] != '?') cout << s[i];
    if(s[i] == 'W') return track(i + 1, rem + 1);
    if(s[i] == 'L') return track(i + 1, rem - 1);
    if(s[i] == 'D') return track(i + 1, rem);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n >> k >> s;
    if(solve(0, k)) track(0, k);
    else cout << "NO\n";
    return 0;
}