#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int p[maxn];
bool vis[maxn];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> p[i];
    vector < int > cyc;
    cyc.push_back(0);
    for(int i = 0 ; i < n ; ++i)
        if(!vis[i]){
            int cur = i, len = 0;
            while(!vis[cur]){
                len++;
                vis[cur] = true;
                cur = p[cur] - 1;
            }
            cyc.push_back(len);
        }
    sort(all(cyc));
    int ans = cyc.back();
    cyc.pop_back();
    ans = (ans + cyc.back()) * (ans + cyc.back());
    for(int i = 0 ; i < sz(cyc) - 1 ; ++i) ans += cyc[i] * cyc[i];
    cout << ans << '\n';
    return 0;
}