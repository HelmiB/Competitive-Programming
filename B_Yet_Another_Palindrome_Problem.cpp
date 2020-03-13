#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n ; ++i) cin >> a[i];
        bool ok = false;
        for(int i = 0 ; i < n && !ok; ++i)
            for(int j = n - 1 ; j > i + 1; --j)
                if(a[i] == a[j]){
                    ok = true;
                    break;
                }
        cout <<  (ok ? "YES":"NO") << '\n';
    }

    return 0;
}
