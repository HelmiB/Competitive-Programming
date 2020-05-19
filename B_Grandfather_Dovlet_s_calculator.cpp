#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int cnt[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int get(int X){
    string s = to_string(X);
    int ans = 0;
    for(auto c : s) ans += cnt[c - '0'];
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long x1, x2, y1, y2;
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for(int i = a ; i <= b ; ++i)
        ans += get(i);
    cout << ans << '\n';
    return 0;
}
