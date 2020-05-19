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
    int q, x;
    cin >> q >> x;
    vector < pair < int, int > > qs;
    for(int i = 0 ; i < q ; ++i){
        int a, b;
        cin >> a >> b;
        qs.push_back({a, b});
    }
    for(int i = 0 ; i < 12 ; ++i){
        int best = x;
        for(auto y : qs){
            if(x >= y.first && x - y.first + y.second > best)
                best = x - y.first + y.second;
        }
        x = best;
    }
    cout << x << '\n';
    return 0;
}