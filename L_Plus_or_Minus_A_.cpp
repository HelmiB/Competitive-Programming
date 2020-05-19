#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[330];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    char op = '+';
    int mask = 0;
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        if(op == '-') a[i] *= -1;
        else mask ^= (1 << i);
        if(i < n - 1) cin >> op;
    }  
    int ans = 1e9;
    for(int i = 0 ; i < (1 << n); ++i){
        int sm = a[0];
        for(int j = 1 ; j < n ; ++j)
            if(i & (1 << j)) sm -= a[j];
            else sm += a[j];
        if(!sm) ans = min(ans, __builtin_popcount(i) - (i & 1));
    }
    cout << (ans < 1e9 ? ans : -1) << '\n';
    return 0;
}