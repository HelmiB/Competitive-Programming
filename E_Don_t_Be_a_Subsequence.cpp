#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int dp[2 * maxn];
vector < int > cnt[30];
string s;

int solve(int i){
    if(i >= sz(s)) return i == sz(s);
    int &ret = dp[i];
    if(~ret) return ret;
    ret = 1e9;
    for(int j = 0 ; j < 26 ; ++j){
        int idx = upper_bound(all(cnt[j]), i - 1) - cnt[j].begin();
        if(idx == sz(cnt[j])){
            ret = 1;
            break;
        }
        ret = min(ret, 1 + solve(cnt[j][idx] + 1));
    }
    return ret;
}

void track(int i){
    if(i >= sz(s)){
        if(i == sz(s)) cout << "a";
        cout << '\n';
        return ;
    }
    int ad = 1e9, k = -1, nxt = -1;
    for(int j = 0 ; j < 26 ; ++j){
        int idx = upper_bound(all(cnt[j]), i - 1) - cnt[j].begin();
        if(idx == sz(cnt[j])){
            k = j;
            nxt = sz(s) + 1;
            break;
        }
        int sm = 1 + solve(cnt[j][idx] + 1);
        if(sm < ad) ad = sm, k = j, nxt = cnt[j][idx] + 1;
    }
    cout << (char)(k + 'a');
    track(nxt);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for(int i = 0 ; i < sz(s); ++i) cnt[s[i] - 'a'].push_back(i);
    memset(dp, -1, sizeof dp);
    solve(0);
    track(0);
    return 0;
}