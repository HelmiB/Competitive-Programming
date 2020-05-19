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
    int n;
    cin >> n;
    vector < pair < int, int > > s;
    for(int i = 0 ; i < n ; ++i){
        int l, r;
        cin >> l >> r;
        s.push_back({l, -1});
        s.push_back({r, 1});
    }
    sort(all(s));
    int in = 0;
    for(int i = 0 ; i < 2 * n ; ++i){
        in -= s[i].second;
        if(in > 2) return cout << "NO\n", 0;
    }

    cout << "YES\n";
    return 0;
}