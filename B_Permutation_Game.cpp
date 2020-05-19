#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector < int > rs(n + 1, -1), a(m);
    set < int > rem;
    for(int i = 1 ; i <= n ; ++i) rem.insert(i);
    for(int i = 0 ; i < m ; ++i) cin >> a[i];
    int sm = n;
    for(int i = 0 ; i < m - 1 ; ++i)
        if(a[i + 1] > a[i]){
            if(rs[a[i]] == -1) sm--;
            rs[a[i]] = a[i + 1] - a[i];
            rem.erase(rs[a[i]]);
        }else{
            if(rs[a[i]] == -1) sm--;
            rs[a[i]] = n - a[i] + a[i + 1];
            rem.erase(rs[a[i]]);
        }
    if(sm != sz(rem)) return cout << -1 << '\n', 0;
    for(int i = 1 ; i <= n ; ++i)
        if(rs[i] == -1){
            rs[i] = *rem.begin();
            rem.erase(rs[i]);
        }
    for(int i = 0 ; i < m - 1 ; ++i){
        int ad = 0;
        if(a[i + 1] > a[i]) ad = a[i + 1] - a[i];
        else ad = n - a[i] + a[i + 1];
        if(ad != rs[a[i]]) return cout << -1 << '\n', 0;
    }
    for(int i = 1 ; i <= n ; ++i) cout << rs[i] << ' ';
    cout << '\n';
    return 0;
}