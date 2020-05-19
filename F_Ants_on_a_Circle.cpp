#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 300500;
long long mod = 1e9 + 7;
long long ans[maxn];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector < long long > finish;
    int n;
    long long m, t;
    cin >> n >> m >> t;
    mod = n * 1LL * m;
    vector < pair < long long, int > > start(n);
    int idx = 0;
    long long tot = 0;
    for(auto &x : start){
        cin >> x.first;
        char c;
        cin >> c;
        x.second = idx++;
        long long sp = (c == 'L' ? -1:1);
        finish.push_back((x.first + (t % m * sp) - 1 + m) % m + 1);
        tot = (tot + (t % mod * sp) + mod) % mod;
    }
    sort(all(start));
    sort(all(finish));
    long long tot_move = 0;
    for(int i = 0 ; i < n ; ++i)
        tot_move = (tot_move + (finish[i] - start[i].first) + mod) % mod;
    tot = (tot - tot_move) / m;
    tot %= n;
    if(tot < 0) tot += n;
    idx = 0;
    for(auto x : start) ans[x.second] = finish[(tot + idx++) % n];
    for(int i = 0 ; i < n ; ++i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}