#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int sz[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    set < pair < int, int > > in;
    for(int i = 0 ; i < n ; ++i){
        cin >> sz[i];
        in.insert({sz[i], i});
    }
    while(q--){
        string s;
        int x;
        cin >> s;
        if(s[0] == 'i'){
            cin >> x;
            if(in.upper_bound({x, -1}) == in.end()){
                cout << -1 << '\n';
                continue;
            }
            auto u = *in.upper_bound({x, -1});
            in.erase(u);
            cout << u.second + 1 << '\n';
        }else{
            cin >> x;
            --x;
            in.insert({sz[x], x});
        }
    }
    return 0;
}