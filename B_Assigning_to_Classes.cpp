#include<bits/stdc++.h>
using namespace std;
const int maxn = 200500;
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
        for(int i = 0 ; i < 2 * n ; ++i) cin >> a[i];
        sort(a, a + 2 * n);
        cout << a[n] - a[n - 1] << '\n';
    }
    return 0;
}
