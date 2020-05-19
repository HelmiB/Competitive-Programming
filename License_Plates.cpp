#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int n;
string s;
int solve(int pos, char pr){
    if(pos == n) return 1;
    int ans = 0;
    if(s[pos] == 'd'){
        for(char c = '0'; c <= '9' ; ++c)
            if(c != pr)
                ans += solve(pos + 1, c);
    }else{
        for(char c = 'a'; c <= 'z' ; ++c)
            if(c != pr)
                ans += solve(pos + 1, c);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    n = sz(s);
    cout << solve(0, '*') << '\n';
    return 0;
}