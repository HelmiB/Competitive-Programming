#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 9;
const int p = 131;
int sm[maxn], pos[maxn], L[maxn], R[maxn];
long long h[maxn];

struct Math{
    private: long long f[maxn];
    public:
    Math(){f[0] = 0;};
    long long add(long long x, long long y) { 
        x += y;
        if(x >= mod) x -= mod;
        if(x < 0) x += mod;
        return x;
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

long long get(int L, int R){
    return math.mul(math.add(h[R], (L > 0 ? -h[L - 1]:0)), math.inv(math.fast_pow(p, L)));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    sm[0] = s[0] - '0';
    for(int i = 1 ; i < sz(s) ; ++i) sm[i] = sm[i - 1] + s[i] - '0';
    int nx = n;
    for(int i = sz(s) - 1 ; i >= 0 ; --i){
        if(s[i] == '0') nx = i;
        R[i] = nx;
    }
    nx = -1;
    for(int i = 0 ; i < sz(s) ; ++i){
        if(s[i] == '0') nx = i;
        L[i] = nx;
    }
    vector < pair < int, int > > v;
    for(int i = 0 ; i < sz(s) ; ++i) v.push_back({s[i] - '0', i});
    string t = "";
    
    for(int i = 0 ; i < sz(v) ; ++i){
        if(!v[i].first){
            pos[v[i].second] = sz(t);
            t += "0";
            continue;
        }
        int j = i;
        while(j < sz(v) && v[j].first) ++j;
        int sm = j - i;
        if(sm % 2) t += "1";
        i = j - 1;
    }
    long long pw = 1;
    for(int i = 0 ; i < sz(t) ; ++i){
        h[i] = math.add(i ? h[i - 1]:0, math.mul(t[i] - '0' + 151564, pw));
        pw = math.mul(pw, p);
    }
    int q;
    cin >> q;
    while(q--){
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        l1--; l2--;
        int ad1 = sm[l1 + len - 1] - (l1 > 0 ? sm[l1 - 1]:0);
        int ad2 = sm[l2 + len - 1] - (l2 > 0 ? sm[l2 - 1]:0);
        if(ad1 != ad2){
            cout << "No\n";
            continue;
        }
        if(ad1 == len){
            cout << "Yes\n";
            continue;
        }
        int ad = 0;
        long long r1 = get(pos[R[l1]], pos[L[l1 + len - 1]]), r2 = get(pos[R[l2]], pos[L[l2 + len - 1]]);
        if((R[l1] - l1) % 2){
            r1 = math.mul(r1, p);
            r1 = math.add(r1, 151565);
            ad = 1;
        }
        if((l1 + len - 1 - L[l1 + len - 1]) % 2) r1 = math.add(r1, math.mul(151565, math.fast_pow(p, pos[L[l1 + len - 1]] - pos[R[l1]] + ad)));
        ad = 0;
        if((R[l2] - l2) % 2){
            r2 = math.mul(r2, p);
            r2 = math.add(r2, 151565);
            ad = 1;
        }
        if((l2 + len - 1 - L[l2 + len - 1]) % 2) r2 = math.add(r2, math.mul(151565, math.fast_pow(p, pos[L[l2 + len - 1]] - pos[R[l2]] + ad)));
        cout << (r1 == r2 ? "Yes":"No") << '\n';
    }
    return 0;
}
