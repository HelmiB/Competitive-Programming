#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
char g[maxn][maxn];
int w[maxn][maxn];

int get(int a, int b, int c, int d){
    return w[c][d] - w[a - 1][d] - w[c][b - 1] + w[a - 1][b - 1];
}

bool is_border(int a, int b, int x, int y){
    int c = a + 3 * x + 2 * y + 1;
    int d = b + 2 * x + y + 1;
    return (get(a, b, a, d) == 2 * x + y + 2)
        && (get(a, b, c, b) == )
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    

    return 0;
}