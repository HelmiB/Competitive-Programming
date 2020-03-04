#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
vector < pair < int, int > > a;
vector < int > vs;
map < int, int > vid, xid;

struct BIT{
    private: long long tree[maxn + 10];
    public:
    void add(int x, long long v){for(x++; x < maxn; x += x & -x)tree[x] += v;}
    long long get(int x){long long ret = 0; for(x++; x; x -= x & -x)ret += tree[x]; return ret;}
 
}b1, b2;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        a.push_back({x, 0});
    }
    for(int i = 0 ; i < n ; ++i){
        int v;
        cin >> v;
        a[i].second = v;
        vs.push_back(v);
    }
    sort(all(a));
    sort(all(vs));
    vs.erase(unique(all(vs)), vs.end());
    int idx = 1;
    for(auto v : vs) vid[v] = idx++;
    long long ans = 0;
    for(int i = 0 ; i < n ; ++i){
        int cnt = b1.get(vid[a[i].second]);
        long long sm = b2.get(vid[a[i].second]);
        ans += cnt * 1LL * a[i].first - sm;
        b1.add(vid[a[i].second], 1);
        b2.add(vid[a[i].second], a[i].first);
    }
    cout << ans << '\n';
    return 0;
}
