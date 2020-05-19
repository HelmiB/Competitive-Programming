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
    vector < int > x(n);
    vector < long long > p(n), s(n);
    for(auto &a : x) cin >> a;
    sort(all(x));
    p[0] = s[n - 1] = 0;
    for(int i = 1 ; i < n ; ++i) p[i] = p[i - 1] + (x[i] - x[i - 1]) * 1LL * i;
    for(int i = n - 2 ; i >= 0 ; --i) s[i] = s[i + 1] + (x[i + 1] - x[i]) * 1LL * (n - i - 1);
    long long sm = 1e18;
    for(int i = 0 ; i < n ; ++i) sm = min(sm, p[i] + s[i]);
    for(int i = 0 ; i < n ; ++i)
        if(sm == s[i] + p[i]){
            cout << x[i] << '\n';
            return 0;
        }
    return 0;
}