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
    int n, k;
    cin >> n >> k;
    vector < int > xs;
    for(int i = 2 ; i * i <= n ; ++i)
        while(n % i == 0){
            n /= i;
            xs.push_back(i);
        }
    if(n > 1) xs.push_back(n);
    if(sz(xs) < k) return cout << -1 << '\n', 0;
    for(int i = 0 ; i < k - 1 ; ++i) cout << xs[i] << ' ';
    long long p = 1;
    for(int i = k - 1 ; i < sz(xs) ; ++i) p *= xs[i];
    cout << p << '\n';
    return 0;
}