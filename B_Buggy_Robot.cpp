#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int l, r, u, d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    int n;
    cin >> n;
    cin >> s;
    for(auto c : s){
        if(c == 'L') l++;
        if(c == 'R') r++;
        if(c == 'U') u++;
        if(c == 'D') d++;
    }
    cout << 2 * (min(l, r) + min(u, d)) << '\n';
    return 0;
}
