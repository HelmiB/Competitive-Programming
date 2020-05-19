#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[110][110];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    if(k > n * n) return cout << -1 << '\n', 0;
    int i = 0, j = 0;
    for(; i < n && k; ++i){
        for(j = 0 ; j < n && k; ++j){
            if(a[i][j]) continue;
            if(i == j){
                a[i][j] = 1;
                k--;
            }else{
                a[i][j] = a[j][i] = 1;
                k -= 2;
            }
            if(k <= 1) break;
        }
        if(k <= 1) break;
    }
    if(k){
        if(j >= i) i++;
        if(i == n || a[i][i]) return cout << -1 << '\n', 0;
        a[i][i] = 1;
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}