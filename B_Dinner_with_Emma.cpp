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
    int best = -1;
    for(int i = 0 ; i < n ; ++i){
        int x = 1e9;
        for(int j = 0 ; j < m ; ++j){
            int y;
            cin >> y;
            x = min(x, y);
        }
        best = max(best, x);
    }
    cout << best << '\n';
    return 0;
}
