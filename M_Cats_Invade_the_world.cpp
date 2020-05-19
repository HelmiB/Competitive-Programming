#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
pair < int , int > rs[maxn], cs[maxn];

struct BIT{
    private: long long tree[maxn + 10];
    public:
    void add(int x, long long v){for(x++; x < maxn; x += x & -x)tree[x] += v;}
    long long get(int x){long long ret = 0; for(x++; x; x -= x & -x)ret += tree[x]; return ret;}
 
}C, R, Csm, Rsm;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long ans = 0;
    int n, q;
    cin >> n >> q;
    for(int i = 1 ; i <= q; ++i){
        int t;
        cin >> t;
        if(t == 1){
            int r, v;
            cin >> r >> v;
            ans += n * 1LL * v;
            int cnt = C.get(maxn) - C.get(rs[r].second);
            ans -= (n - cnt) * 1LL * rs[r].first;
            cnt = Csm.get(maxn) - Csm.get(rs[r].second);
            ans -= cnt;
            R.add(rs[r].second, -1);
            Rsm.add(rs[r].second, -rs[r].first);
            rs[r] = {v, i};
            R.add(rs[r].second, 1);
            Rsm.add(i, v);
        }else{
            int c, v;
            cin >> c >> v;
            ans += n * 1LL * v;
            int cnt = R.get(maxn) - R.get(cs[c].second);
            ans -= (n - cnt) * 1LL * cs[c].first;
            cnt = Rsm.get(maxn) - Rsm.get(cs[c].second);
            ans -= cnt;
            C.add(cs[c].second, -1);
            Csm.add(cs[c].second, -cs[c].first);
            cs[c] = {v, i};
            C.add(cs[c].second, 1);
            Csm.add(cs[c].second, v);
        }
        cout << ans << '\n';
    }

    return 0;
}