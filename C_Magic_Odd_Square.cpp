#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[50][50];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int cur = 1;
    for(int i = 0 ; i < n ; ++i){
        int l, r;
        if(i <= n / 2) l = n / 2 - i, r = n / 2 + i;
        else l = n / 2 - n + 1 + i, r = n / 2 + n - 1 - i;
        for(int j = l ; j <= r ; ++j) a[i][j] = cur, cur +=2;
    }
    cur = 2;
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(a[i][j]) cout << a[i][j] << ' ';
            else cout << cur << ' ', cur += 2;
        }
        cout << '\n';
    }
    return 0;
}