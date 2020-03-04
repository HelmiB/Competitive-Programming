#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < int > dv[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1 ; i < maxn ; ++i)
        for(int j = 1 ; j * j <= i ; ++j)
            if(i % j == 0){
                dv[i].push_back(j);
                if(i / j != j) dv[i].push_back(i / j);
            }
            
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 1e9, xx = -1, y = -1, z = -1;
        for(int j = 1 ; j <= 1e5; ++j)
            for(auto i : dv[j]){
                    int cnt = abs(a - i) + abs(b - j);
                    int md1 = c % j, md2 = j - c % j;
                    bool flag = true;
                    if(c != md1 && md1 < md2) cnt += md1, flag = false;
                    else cnt += md2;
                    if(cnt < ans){
                        ans = cnt;
                        xx = i;
                        y = j;
                        z = c + (flag ? md2:-md1);
                    }
                }
        cout << ans << '\n';
        cout << xx << ' ' << y << ' ' << z << '\n';
    }
    return 0;
}
