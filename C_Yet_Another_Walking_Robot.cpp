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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int x = 0, y = 0;
        for(auto c : s){
            if(c == 'L') x--;
            if(c == 'R') x++;
            if(c == 'D') y--;
            if(c == 'U') y++;
        }
        int ans = 1e9, l = -1, r = -1;
        map < pair < int, int > , int > pos;
        pos[{0, 0}] = 0;
        x = 0, y = 0;
        for(int i = 0 ; i < n ; ++i){
            char c = s[i];
            if(c == 'L') x--;
            if(c == 'R') x++;
            if(c == 'D') y--;
            if(c == 'U') y++;
            if(pos.find({x, y}) != pos.end()){
                int lo = pos[make_pair(x, y)] + 1;
                int hi = i + 1;
                if(hi - lo + 1 < ans){
                    ans = hi - lo + 1;
                    l = lo;
                    r = hi;
                }
            }
            pos[{x, y}] = i + 1;
        }
        if(~l) cout << l << ' ' << r << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
