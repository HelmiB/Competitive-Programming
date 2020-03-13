#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
long long C[1010][1010];
long long der[5];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 0 ; i < 1010 ; ++i)
        for(int j = 0 ; j <= i ; ++j){
            if(!j || j == i) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    der[0] = 1;
    der[1] = 0;
    for(int i = 2 ; i < 5 ; ++i) der[i] = (i - 1) * 1LL * (der[i - 1] + der[i - 2]);
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    for(int i = 0 ; i <= k ; ++i)
        ans += C[n][i] * der[i];
    cout << ans << '\n';
    return 0;
}
