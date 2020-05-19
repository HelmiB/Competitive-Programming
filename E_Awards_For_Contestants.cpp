#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 3050;
const int mod = 1e9 + 7;
pair < int , int > arr[maxn];
int n, ans[maxn];

struct SparseTable{
    long long t[maxn],dp[maxn][35], lg[maxn];
    SparseTable(){
        lg[1] = 0 ;
        for(int i = 2 ; i < maxn; ++i)
            lg[i] = 1 + lg[i/2];
    }
    long long op(long long a, long long b){
        return max(a, b);
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
    for(int i = 0 ; i < n ; ++i) cin >> arr[i].first, arr[i].second = i;
    sort(arr, arr + n);
    reverse(arr, arr + n);
    for(int i = 0 ; i < n - 1 ; ++i) spt.t[i] = arr[i].first - arr[i + 1].first;
    spt.t[n - 1] = arr[n - 1].first;
    spt.build(n);
    int a = -1, b = -1, c = -1;
    int idx1 = -1, idx2 = -1;
    for(int i = 0 ; i < n - 2 ; ++i){
        int cnt1 = i + 1;
        int l = (cnt1 + 1) / 2;
        int r = 2 * cnt1;
        int ta = arr[i].first - arr[i + 1].first, tb = -1e9, tc = -1e9;
        for(int j = i + l ; j <= min(i + r, n - 2); ++j){
            int cnt2 = j - i;
            cnt1 = i + 1;
            tb = arr[j].first - arr[j + 1].first;
            if(cnt1 > cnt2) swap(cnt1, cnt2);
            int l1 = (cnt2 + 1) / 2, r1 = 2 * cnt1;
            if(l1 > r1) continue;
            int ql = j + l1;
            int qh = min(j + r1, n - 1);
            if(ql > qh) continue;
            int tc = spt.query(ql, qh);
            if(a < ta || (a == ta && b < tb) || (a == ta && b == tb && c < tc)){
                a = ta;
                b = tb;
                c = tc;
                idx1 = i;
                idx2 = j;
            }
        }
    }
    memset(ans, -1, sizeof ans);
    int cnta = idx1 + 1, cntb = idx2 - idx1;
    for(int i = 0 ; i <= idx1 ; ++i) ans[arr[i].second] = 1;
    for(int i = idx1 + 1 ; i <= idx2 ; ++i) ans[arr[i].second] = 2;
    int j = idx2 + (max(cnta, cntb) + 1) / 2;
    for(int k = idx2 + 1 ; k <= j; ++k) ans[arr[k].second] = 3;
    while(j < n && spt.t[j] != c){
        ans[arr[j].second] = 3;
        ++j;
    }
    int cntc = j - idx2;
    //cout << a << ' ' << b << ' ' << c << '\n';
    assert(j < n);
    assert(2 * cnta >= cntb && 2 * cnta >= cntc &&
           2 * cntb >= cnta && 2 * cntb >= cntc && 
           2 * cntc >= cnta && 2 * cntc >= cntb);
    ans[arr[j].second] = 3;
    for(int i = 0 ; i < n ; ++i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}