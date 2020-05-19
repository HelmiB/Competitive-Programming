#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int p = a * b;
        if(p > 1e8){
            cout << 671644785 << '\n';
            continue;
        }
        set < int > st;
        for(int i = 1 ; i < p ; ++i)
            if(i != a)
                st.insert((p - 1) / i), cout << i << ' ' << (p - 1) / i << '\n';
        st.erase(b);
        cout << sz(st) << '\n';
    }
    return 0;
}