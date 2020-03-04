#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int pos[2 * maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    int n;
    cin >> s >> n;
    s += s;
    int idx = 2 * sz(s);
    for(int i = sz(s) - 1 ; i >= 0 ; --i){
        if(s[i] == 'E') idx = i;
        pos[i] = idx;
    }
    long long ans = 0;
    for(int i = 0 ; i < sz(s) /  2 ; ++i)
        if(pos[i] - i + 1 <= n)
            ans += i + n - pos[i];
    cout << ans << '\n';
    return 0;
}
