#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 700500;
const int mod = 1e9 + 7;
int l[maxn], r[maxn];

struct SparseTable{
    long long t[maxn],dp[maxn][35], lg[maxn];
    SparseTable(){
        lg[1] = 0 ;
        for(int i = 2 ; i < maxn; ++i)
            lg[i] = 1 + lg[i/2];
    }
    long long op(long long a, long long b){
        return min(a, b);
    }
    void build(int n){
        assert(n < maxn);
        for(int i = 0 ; i < n ; ++i)
            dp[i][0] = t[i];

        for(int j = 1 ; j <= 20 ; ++j)
            for(int i = 0 ; (i + (1 << j)) <= n ; ++i)
                dp[i][j] = op(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]); 
    }
    long long query(int l , int r){
        assert(l >= 0 && r >= 0 && l < maxn && r < maxn);
        int len = r - l + 1; 
        return op(dp[l][lg[len]], dp[r - (1 << lg[len]) + 1][lg[len]]);
    }
}spt;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector < int > x;
    for(int i = 0 ; i < n ; ++i){
        cin >> l[i] >> r[i];
        x.push_back(l[i]);
        x.push_back(r[i]);
        x.push_back(r[i] + 1);
    }
    sort(all(x));
    x.erase(unique(all(x)), x.end());
    for(int i = 0 ; i < n ; ++i){
        l[i] = lower_bound(all(x), l[i]) - x.begin();
        r[i] = lower_bound(all(x), r[i]) - x.begin();
        spt.t[l[i]]++;
        spt.t[r[i] + 1]--;
    }
    for(int i = 1 ; i < sz(x) ; ++i) spt.t[i] += spt.t[i - 1];
    spt.build(sz(x));
    for(int i = 0 ; i < n ; ++i)
        if(spt.query(l[i], r[i]) >= 2)
            return cout << i + 1 << '\n', 0;
    cout << -1 << '\n';
    return 0;
}