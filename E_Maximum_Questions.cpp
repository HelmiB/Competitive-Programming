#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int acc[2][2][maxn], emp[maxn];
pair < int, int > dp[maxn];
string s, t;
int n, m;


int get(int c, int idx, int l, int r){
    return acc[c][idx][r] - (l ? acc[c][idx][l - 1]:0);
}

int get_emp(int l, int r){
    return emp[r] - (l ? emp[l - 1]:0);
}

pair < int, int > solve(int i){
    if(i > n - m) return {0, 0};
    auto &ret = dp[i];
    if(~ret.first) return ret;
    auto f = solve(i + 1);
    pair < int, int > s = {-1, -1};
    int ad = get(0, i % 2, i, i + m - 1) + get(1, (i + 1) % 2, i, i + m - 1);
    int em = get_emp(i, i + m - 1);
    if(em + ad == m){
        s = solve(i + m);
        s.first++;
        s.second += em;
    }
    if(f.first == s.first){
        if(f.second < s.second) ret = f;
        else ret = s;
    }else if(f.first > s.first) ret = f;
    else ret = s;
    return ret;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> s >> m;
    for(int i = 0 ; i < n ; ++i)
        if(s[i] != '?')  acc[s[i] - 'a'][i % 2][i] = 1;
        else emp[i] = 1;
    for(int i = 1 ; i < n ; ++i) emp[i] += emp[i - 1];
    for(int i = 1 ; i < n ; ++i)
        for(int j = 0 ; j < 2 ; ++j)
            for(int k = 0 ; k < 2 ; ++k)
                acc[j][k][i] += acc[j][k][i - 1];
    for(int i = 0 ; i < n ; ++i) dp[i] = {-1, -1};
    cout << solve(0).second << '\n';
    return 0;
}