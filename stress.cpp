#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(l, r)(rng); [l, r]

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n = 20, m = 3;
    vector < int > a;
    cout << n << '\n';
    for(int i = 0 ; i < n ; ++i){
        int x = uniform_int_distribution<int>(1, n)(rng);
        a.push_back(x);
        cout << x << ' ';
    }
    cout << '\n';
    for(int i = 0 ; i < n ; ++i){
        int x = uniform_int_distribution<int>(1, 500)(rng);
        cout << x - 250 << ' ';
    }
    cout << '\n';
    cout << m << '\n';
    int i = 0, j = 0;
    int prv = 0;
    while(i < n && j < m){
        if(a[i] <= prv){
            ++i;
            continue;
        }
        if(n - i == m - j){
            cout << a[i] << ' ';
            prv = a[i];
            ++i; ++j;
            continue;
        }
        int ad = uniform_int_distribution<int>(1, 1e9)(rng) % 3;
        if(ad < 2){
            cout << a[i] << ' ';
            prv = a[i];
            ++j;
        }
        ++i;
    }
    while(j < m){
        cout << prv + 1 << ' ';
        prv++;
        j++;
    }
    cout << '\n';
    return 0;
}
