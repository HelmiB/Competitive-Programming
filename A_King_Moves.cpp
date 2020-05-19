#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

bool valid(int i, int j){
    return i > 0 && i < 9 && j > 0 && j < 9;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};    
    int dy[8] = {-1, 1, 0, -1, 1, 0, -1, 1};    
    char c;
    int i, j;
    cin >> c >> j;
    i = c - 'a' + 1;
    int ans = 0;
    for(int k = 0 ; k < 8 ; ++k)
        ans += valid(i + dx[k], j + dy[k]);
    cout << ans << '\n';
    return 0;
}