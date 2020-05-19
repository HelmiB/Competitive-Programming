#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
int p[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> p[i];
    string s;
    cin >> s;
    long long sa = 0, sb = 0;
    for(int i = 0 ; i < n ; ++i){
        if(s[i] == 'A') sa += p[i];
        else sb += p[i];
    }
    long long ans = sb;
    long long xa = sa, xb = sb;
    for(int i = 0 ; i < n ; ++i){
        if(s[i] == 'A'){
            sa -= p[i];
            sb += p[i];
        }else{
            sa += p[i];
            sb -= p[i];
        }
        if(s[n - i - 1] == 'A'){
            xa -= p[n - i - 1];
            xb += p[n - i - 1];
        }else{
            xa += p[n - i - 1];
            xb -= p[n - i - 1];
        }
        ans = max(ans, sb);
        ans = max(ans, xb);
    }
    cout << ans << '\n';
    return 0;
}