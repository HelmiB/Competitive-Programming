#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 300500;
const int mod = 1e9 + 7;
vector < pair < int, pair < int, int > > > qs;
int a[maxn];

int solve(int cur){
    for(auto q : qs)
        if(q.second.first <= cur && cur <= q.second.second){
            if(q.first == 1){
                if(cur == q.second.first) cur = q.second.second;
                else cur--;
            }else cur = q.second.second - (cur - q.second.first);
        }
    return a[cur - 1];
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q, m;
    cin >> n >> q >> m;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    qs.resize(q);
    for(auto &x : qs) cin >> x.first >> x.second.first >> x.second.second;
    reverse(all(qs));
    for(int i = 0 ; i < m ; ++i){
        int pos;
        cin >> pos;
        cout << solve(pos) << ' ';
    }
    cout << '\n';
    return 0;
}