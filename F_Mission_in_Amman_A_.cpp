#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int pos[maxn], s[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    int ans = m;
    for(int i = 0 ; i < n ; ++i){
        int p;
        cin >> p;
        pos[p]++;
        if(pos[p] == 1) ans--;
        s[i] = p;
    }
    while(q--){
        int st, p;
        cin >> st >> p;
        --st;
        pos[s[st]]--;
        if(!pos[s[st]]) ans++;
        s[st] = p;
        pos[p]++;
        if(pos[p] == 1) ans --;
        cout << ans << '\n';
    }
    return 0;
}