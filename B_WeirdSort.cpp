#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
bool can[1010];
int a[1010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 0 ; i < n ; ++i) can[i] = false;
        for(int i = 0 ; i < n ; ++i) cin >> a[i];
        for(int i = 0 ; i < m ; ++i){
            int x;
            cin >> x;
            can[x - 1] = true;
        }
        bool ok = true;
        for(int i = 0 ; i < n; ++i)
            for(int j = 0 ; j < i ; ++j)
                if(a[j] > a[i]){
                    for(int k = j ; k < i ; ++k)
                        if(!can[k]){
                            ok = false;
                            break;
                        }
                }
        cout << (ok ? "YES\n":"NO\n");
    }
    return 0;
}
