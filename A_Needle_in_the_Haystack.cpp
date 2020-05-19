#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
string s, pat;
int n, m, f[maxn];

void failure(){
    f[0] = 0;
    for(int i = 1 ; i < m ; ++i){
        int k = f[i - 1];
        while(k > 0 && pat[k] != pat[i]) k = f[k - 1];
        if(pat[k] == pat[i]) f[i] = ++k;
        else f[i] = k;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> pat;
        m = sz(pat);
        failure();
        cout << f[m - 1] << '\n';
    }
    return 0;
}