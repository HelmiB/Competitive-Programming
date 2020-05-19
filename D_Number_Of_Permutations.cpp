#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 998244353;

struct Math{
    private: long long f[maxn];
    public:
    Math(){f[0] = 0;};
    long long add(long long x, long long y) { 
        return (x + y + mod) % mod;
    }
    long long mul(long long x, long long y) { return (add(x, mod) * add(y, mod)) % mod; }
    long long fast_pow(long long n, long long k){
            if(k == 0) return 1LL;
            long long ans = fast_pow(n, k >> 1);
            ans = mul(ans, ans);
            if(k & 1) ans = mul(n, ans);
            return ans;
    }
    long long inv(long long x) { return fast_pow(x, mod - 2); }
    void init_fact(){
        f[0] = 1LL;
        for(int i = 1 ; i < maxn ; ++i)
            f[i] = mul(i, f[i - 1]);
    }
    long long fact(int x){
        assert(x >= 0 && x < maxn);
        if(!f[0]) init_fact();
        return f[x];
    };
}math;

inline bool cmp(const pair < int, int > &a, const pair < int, int > &b){
    return a.second < b.second;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector < pair < int, int > > v(n);
    for(auto &x : v) cin >> x.first >> x.second;
    vector < pair < int, int > > t = v;
    long long ans = math.fact(n);
    sort(all(v));
    long long p = 1;
    for(int i = 0 ; i < n ; ++i){
        int j = i;
        while(j < n && v[j].first == v[i].first) ++j;
        p = math.mul(p, math.fact(j - i));
        i = j - 1;
    }
    ans = math.add(ans, -p);
    p = 1;
    sort(all(t), cmp);
    for(int i = 0 ; i < n ; ++i){
        int j = i;
        while(j < n && t[j].second == t[i].second) j++;
        p = math.mul(p, math.fact(j - i));
        i = j - 1;
    }
    ans = math.add(ans, -p);
    p = 1;
    for(int i = 0 ; i < n - 1 ; ++i)
        if(v[i].second > v[i + 1].second)
            p = 0;
    for(int i = 0 ; i < n && p; ++i){
        int j = i;
        vector < int > tm;
        while(j < n && v[j].first == v[i].first){
            tm.push_back(v[j].second);
            ++j;
        }
        for(int k = 0 ; k < sz(tm) ; ++k){
            int r = k;
            while(r < sz(tm) && tm[r] == tm[k]) r++;
            p = math.mul(p, math.fact(r - k));
            k = r - 1;
        }
        i = j - 1;
    }
    ans = math.add(ans, p);
    cout << ans << '\n';
    return 0;
}