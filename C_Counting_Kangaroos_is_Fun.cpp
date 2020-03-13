#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[5 * maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    set < pair < int, int > > st;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    sort(a, a + n);
    int ans = n;
    for(int i = n / 2; i < n ; ++i) st.insert({a[i], i});
    for(int i = 0 ; i < n / 2 ; ++i)
        if(st.upper_bound({2 * a[i] - 1, 1e9}) != st.end()){
            ans--;
            st.erase(st.upper_bound({2 * a[i] - 1, 1e9}));
        }
    cout << ans << '\n';
    return 0;
}
