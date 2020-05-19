#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
char a[110][110];
int n, m;

void checkV(char x, char y, char z){
    int w = 0;
    for(int i = 0 ; i < n ; ++i){
        bool flag = true;
        int j;
        for(j = 0 ; j < m && flag; ++j)
            flag &= (a[i][j] == x);
        if(!flag){
            if(j > 1) return;
            break;
        }
        ++w;
    }
    if(!w || (n % 3) || (n / w) != 3) return;
    for(int i = w ; i < 2 * w ; ++i){
        bool flag = true;
        for(int j = 0 ; j < m && flag; ++j)
            flag &= (a[i][j] == y);
        if(!flag) return;
    }
    for(int i = w ; i < 2 * w ; ++i){
        bool flag = true;
        for(int j = 0 ; j < m && flag; ++j)
            flag &= (a[i][j] == y);
        if(!flag) return;
    }
    for(int i = 2 * w ; i < n ; ++i){
        bool flag = true;
        for(int j = 0 ; j < m && flag; ++j)
            flag &= (a[i][j] == z);
        if(!flag) return;
    }
    cout << "YES\n";
    exit(0);
}

void checkH(char x, char y, char z){
    int w = 0;
    for(int i = 0 ; i < m ; ++i){
        bool flag = true;
        int j;
        for(j = 0 ; j < n && flag; ++j)
            flag &= (a[j][i] == x);
        if(!flag){
            if(j > 1) return;
            break;
        }
        ++w;
    }
    if(!w || (m % 3) || (m / w) != 3) return;
    for(int i = w ; i < 2 * w ; ++i){
        bool flag = true;
        for(int j = 0 ; j < n && flag; ++j)
            flag &= (a[j][i] == y);
        if(!flag) return;
    }
    for(int i = w ; i < 2 * w ; ++i){
        bool flag = true;
        for(int j = 0 ; j < n && flag; ++j)
            flag &= (a[j][i] == y);
        if(!flag) return;
    }
    for(int i = 2 * w ; i < m ; ++i){
        bool flag = true;
        for(int j = 0 ; j < n && flag; ++j)
            flag &= (a[j][i] == z);
        if(!flag) return;
    }
    cout << "YES\n";
    exit(0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n; ++i)
        for(int j = 0 ; j < m ; ++j)
            cin >> a[i][j];
    checkV('R', 'B','G');
    checkV('R', 'G','B');
    checkV('B', 'G', 'R');
    checkV('B', 'R', 'G');
    checkV('G', 'R', 'B');
    checkV('G', 'B', 'R');
    checkH('B', 'R', 'G');
    checkH('R', 'B','G');
    checkH('R', 'G','B');
    checkH('B', 'G', 'R');
    checkH('G', 'R', 'B');
    checkH('G', 'B', 'R');
    cout << "NO\n";
    return 0;
}