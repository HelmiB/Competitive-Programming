#include<bits/stdc++.h>
using namespace std;
const int maxn = 100500;
const int mod = 1e9 + 7;
pair < int, int > dp[30][30][2][2][2][2];
string s;

pair < int, int > solve(int i = 0, int cnt = 0, bool need = false, bool ainfb = false, bool grb = false, bool gra = false){
    if(i == (int)s.length()){
        if(need || !ainfb || !gra) return {-1, 0};
        return {cnt, 1};
    }
    pair < int, int > &ret = dp[i][cnt][need][ainfb][grb][gra];
    if(~ret.first) return ret;
    ret = {0, 0};    
    int d = s[i] - '0';
    for(int a = 0 ; a <= 9 ; ++a)
        for(int b = 0 ; b <= 9 ; ++b){
            if(b > d && !grb) continue;
            if(a > b && !ainfb) continue;
            int sm = a + b;
            bool carry = sm / 10;
            sm %= 10;
            bool nd = need;
            if(carry && !nd) continue;
            if(carry) nd = false;
            if(nd){
                if(sm == 9){
                    auto u = solve(i + 1, 0, true, ainfb | (b > a), grb | (b < d), gra | (a > 0));
                    if(u.first == ret.first) ret.second += u.second;
                    if(u.first > ret.first) ret = u;
                }
            }else{
                auto u = solve(i + 1, (sm == 9 ? cnt + 1:0), false, ainfb | (b > a), grb | (b < d),gra | (a > 0));
                if(u.first == ret.first) ret.second += u.second;
                if(u.first > ret.first) ret = u;
                sm = sm++;
                if(sm == 10) continue;
                u = solve(i + 1, (sm == 9 ? cnt + 1:0), true, ainfb | (b > a), grb | (b < d), gra | (a > 0));
                if(u.first == ret.first) ret.second += u.second;
                if(u.first > ret.first) ret = u;
            }
        }
    return ret;
}

void init(){
    for(int i = 0 ; i < 30 ; ++i)
        for(int j = 0 ; j < 30 ; ++j)
            for(int k = 0 ; k < 2 ; ++k)
                for(int l = 0 ; l < 2 ; ++l)
                    for(int p = 0 ; p < 2 ; ++p)
                        for(int f = 0 ; f < 2 ; ++f)
                            dp[i][j][k][l][p][f] = {-1, -1};
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    s = to_string(n);
    init();
    cout << solve().second << '\n';
    return 0;
}
