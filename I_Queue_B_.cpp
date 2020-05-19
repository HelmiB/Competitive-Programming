#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int ord[maxn], change[maxn], c[maxn][5], have[5];

inline bool cmp(const int &a, const int &b){
    return change[a] < change[b];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int mp[5];
    mp[0] = 1;
    mp[1] = 5;
    mp[2] = 10;
    mp[3] = 20;
    mp[4] = 50;
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> change[i];
        change[i] *= -1;
        for(int j = 0 ; j < 5; ++j){
            cin >> c[i][j];
            change[i] += c[i][j] * mp[j];
        }
        ord[i] = i;
    }
    sort(ord, ord + n, cmp);
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < 5 ; ++j) have[j] += c[ord[i]][j];
        for(int j = 4 ; j >= 0 ; --j)
            while(have[j] && mp[j] <= change[ord[i]]){
                change[ord[i]] -= mp[j];
                have[j]--;
            }
        if(change[ord[i]]) return cout << -1 << '\n', 0;
    }

    for(int i = 0 ; i < n ; ++i) cout << ord[i] + 1 << ' ';
    cout << '\n';
    return 0;
}