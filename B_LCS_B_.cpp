#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int n, m, dp[30][30], s[2][50];
vector < pair < bool, int > > g[2][30];
bool vis[2][30], eq[30][30], neq[30][30], done[2][30];

void dfs(bool idx, int i, int c){
    if(vis[idx][i]) return ;
    vis[idx][i] = true;
    s[idx][i] = c;
    done[idx][i] = true;
    for(auto v : g[idx][i])
        dfs(v.first, v.second, c);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i <= n ; ++i)
        for(int j = 0 ; j <= m ; ++j){
            cin >> dp[i][j];
            if(i && j){
                if(dp[i][j] > max(dp[i][j - 1], dp[i - 1][j])){ 
                    g[0][i].push_back({1, j});
                    g[1][j].push_back({0, i});
                    eq[i][j] = true;
                }
                if(dp[i][j] < dp[i - 1][j - 1] + 1) neq[i][j] = true;
            }
        }
    queue < int > d;
    for(int i = 0 ; i < 26 ; ++i) d.push(i);
    vector < int > pa, pb;
    for(int i = 1 ; i <= n ; ++i)
        if(sz(g[0][i]) && !vis[0][i]){
            dfs(0, i, d.front());
            d.pop();
        }else if(!vis[0][i]){
             if(sz(d)){
                s[0][i] = d.front();
                done[0][i] = true;
                d.pop();
            }else{
                set < int > can;
                for(int i = 0 ; i < 26 ; ++i) can.insert(i);
                for(int  j = 1 ; j <= m ; ++j)
                    if(neq[i][j] && done[1][j])
                        can.erase(s[1][j]);
                assert(sz(can));
                s[0][i] = *can.begin();
                done[0][i] = true;
            } 
        }
    for(int i = 1 ; i <= m ; ++i)
        if(!vis[1][i]){
            if(sz(d)){
                s[1][i] = d.front();
                done[1][i] = true;
                d.pop();
            }else{
                set < int > can;
                for(int i = 0 ; i < 26 ; ++i) can.insert(i);
                for(int  j = 1 ; j <= n ; ++j)
                    if(neq[j][i] && done[0][j])
                        can.erase(s[0][j]);
                assert(sz(can));
                s[1][i] = *can.begin();
                done[1][i] = true;
            }  
        }
    for(int i = 1 ; i <= n; ++i) cout << (char)(s[0][i] + 'a');
    cout << '\n';
    for(int i = 1 ; i <= m; ++i) cout << (char)(s[1][i] + 'a');
    cout << '\n';
    return 0;
}