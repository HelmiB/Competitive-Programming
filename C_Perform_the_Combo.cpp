#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int cnt[30];
int acc[2 * maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        memset(acc, 0, (n + 5) * sizeof acc[0]);
        memset(cnt, 0, sizeof cnt);
        string s;
        cin >> s;
        for(int i = 0 ; i < m ; ++i){
            int p;
            cin >> p;
            acc[p - 1]++;
        }
        for(int i = n - 1 ; i >= 0 ; --i){
            acc[i] += acc[i + 1];
            cnt[s[i] - 'a'] += acc[i] + 1;
        }
        for(int i = 0 ; i < 26 ; ++i) cout << cnt[i] << ' ';
        cout << '\n';
    }

    return 0;
}
