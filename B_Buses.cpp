#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 300500;
const int mod = 1e9 + 7;
map < int, vector < int > > rs;
map < int, int > id;
struct BIT{
    private: long long tree[maxn + 10];
    public:
    void add(int x, long long v){for(x++; x < maxn; x += x & -x)tree[x] += v;}
    long long get(int x){long long ret = 0; for(x++; x; x -= x & -x)ret += tree[x]; return ret;}
 
}bit;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector < int > pos;
    pos.push_back(n);
    pos.push_back(0);
    for(int i = 0 ; i < m ; ++i){
        int l, r;
        cin >> l >> r;
        rs[r].push_back(l);
        pos.push_back(l);
        pos.push_back(r);
    }
    sort(all(pos));
    pos.erase(unique(all(pos)), pos.end());
    int idx = 1;
    for(auto x : pos) id[x] = idx++;
    long long ans = 0;
    bit.add(1, 1);
    for(int i = 0 ; i < sz(pos); ++i){
        ans = 0;
        for(auto l : rs[pos[i]]) ans += (bit.get(maxn)%mod - bit.get(id[l] - 1)%mod + mod) % mod, ans %= mod;
        if(!ans) continue;
        bit.add(id[pos[i]], ans);
        long long x = bit.get(id[pos[i]]);
        if(x < mod) continue;
        bit.add(id[pos[i]], -x);
        bit.add(id[pos[i]], x % mod);
    }
    cout << ans << '\n';
    return 0;
}
