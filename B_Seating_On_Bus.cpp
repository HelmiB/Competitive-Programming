#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int pos[2][2][200];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < min(2 * n, m); ++i) pos[i % 2][0][i / 2] = i + 1;
    for(int i = 2 * n ;  i < m ; ++i) pos[i % 2][1][(i - 2 * n) / 2] = i + 1;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < 2 ; ++j)
            for(int k = 1 ; k >= 0 ; --k)
                if(pos[j][k][i])
                    cout << pos[j][k][i] << ' ';
    cout << '\n';
    return 0;
}