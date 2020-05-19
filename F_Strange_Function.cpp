#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
int a[maxn], p[maxn], dp[maxn], best[maxn];

struct BIT{
    private: long long tree[maxn + 10];
    public:
    void add(int x, long long v){for(x++; x < maxn; x += x & -x)tree[x] += v;}
    long long get(int x){long long ret = 0; for(x++; x; x -= x & -x)ret += tree[x]; return ret;}
 
}bit[4];



int n, m;
vector < int > b;
int solve(int i, int j){
    if(i == n + 1){
        if(j != m + 1) return 1e18;
        return 0;
    }
    if(j == m + 1){
        if(a[i] > b[m]) return p[i] + solve(i + 1, j);
        if(p[i] < 0) return p[i] + solve(i + 1, j);
        return solve(i + 1, j);
    }
    if(a[i] == b[j - 1]) return min(0LL, p[i]) + solve(i + 1, j);
    if(a[i] > b[j - 1] && a[i] < b[j]) return p[i] + solve(i + 1, j);
    int ans = 1e18;
    if(a[i] == b[j]) ans = solve(i + 1, j + 1);
    return min(ans, min(0LL, p[i]) + solve(i + 1, j)); 
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    a[0] = p[0] = 0; 
    for(int i = 1 ; i <= n ; ++i) cin >> a[i];
    for(int i = 1 ; i <= n ; ++i) cin >> p[i];
    map < int, vector < int > > pos;
    vector < pair < int, pair < int, int > > > sorted;
    for(int i = 0 ; i <= n ; ++i){
        pos[a[i]].push_back(i);
        sorted.push_back({a[i], {i, p[i]}});
    }
    sort(all(sorted));
    cin >> m;
    b.resize(m + 2);
    b[0] = 0;
    for(int i = 1 ; i <= m ; ++i) cin >> b[i];
    for(int i = 1 ; i <= n ; ++i) dp[i] = 1e18;
    dp[0] = 0;
    for(int i = 0 ; i <= n + 1 ; ++i){
        bit[1].add(i, p[i]);
        bit[3].add(i, p[i]);
    }
    int l = 0, r = 0;
    for(int i = 1 ; i <= m; ++i){
        if(!pos.count(b[i])) break;
        int j = -1;
        int k = -1;
        auto &u = pos[b[i - 1]];
        while(r < sz(sorted) && sorted[r].first <= b[i]){
            if(sorted[r].second.second < 0)  
                bit[2].add(sorted[r].second.first, sorted[r].second.second);
            bit[3].add(sorted[r].second.first, -sorted[r].second.second);
            r++;
        }
        while(l < sz(sorted) && sorted[l].first <= b[i - 1]){
            if(sorted[l].second.second < 0)  
                bit[0].add(sorted[l].second.first, sorted[l].second.second);
            bit[1].add(sorted[l].second.first, -sorted[l].second.second);
            l++;
        }
        for(auto ps : pos[b[i]]){
            while(j + 1 < sz(u) && u[j + 1] < ps) ++j;
            if(j == -1) continue;
            dp[ps] = dp[u[j]] + bit[0].get(ps - 1) - bit[0].get(u[j])
                              + bit[1].get(ps - 1) - bit[1].get(u[j]);
            if(~k){
                long long ad = dp[k] + bit[2].get(ps - 1) - bit[2].get(k)
                                     + bit[3].get(ps - 1) - bit[3].get(k);
                if(p[ps] < 0) ad += p[ps];
                dp[ps] = min(dp[ps], ad);
            }
            k = ps;
        }
        
    }
    int brute = solve(1, 1);
    if(!pos.count(b[m])) return cout << "NO\n", 0;
    int idx = pos[b[m]].back();
    if(dp[idx] < 1e18){
        for(int i = idx + 1 ; i <= n ; ++i)
            if(a[i] > b[m] || p[i] < 0)
                dp[idx] += p[i];
        cout << "YES\n";
        cout << dp[idx] << '\n';
        //assert(brute == dp[idx]);
        cout << dp[idx] << ' ' << brute << '\n';
        return 0;
    }
    //assert(brute > 1e17);
    cout << dp[idx] << ' ' << brute << '\n';
    cout << "NO\n";
    return 0;
}