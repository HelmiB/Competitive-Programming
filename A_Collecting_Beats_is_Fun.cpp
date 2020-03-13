#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    k *= 2;
    int cnt[10] = {0};
    for(int i = 0 ; i < 4 ; ++i)
        for(int j = 0 ; j < 4 ; ++j){
            char c;
            cin >> c;
            cnt[c - '0']++;
        }
    for(int i = 0 ; i <= 9 ; ++i) if(cnt[i] > k) return cout << "NO\n", 0;
    cout << "YES\n";
    return 0;
}
