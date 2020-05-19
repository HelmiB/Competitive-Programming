#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

struct BIT{
    private: long long tree[maxn + 10];
    public:
    void add(int x, long long v){for(x++; x < maxn; x += x & -x)tree[x] += v;}
    long long get(int x){long long ret = 0; for(x++; x; x -= x & -x)ret += tree[x]; return ret;}
 
}bit;

struct person{
    int s, f, idx;
};

person ps[maxn];
int ans[maxn];
vector < int > en[maxn], ex[maxn];



signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    map < int, vector < person > > m;
    int n, fl;
    cin >> n >> fl;
    vector < int > ts;
    for(int i = 0 ; i < n ; ++i){
        person p;
        int t;
        cin >> t >> p.s >> p.f;
        ts.push_back(t);
        p.idx = i;
        ps[i] = p;
        m[t].push_back(p);
    }
    sort(all(ts));
    ts.erase(unique(all(ts)), ts.end());
    ts.push_back(1e10);
    set < int > in;
    int cur = 1, counter = 0;
    for(int i = 0 ; i < sz(ts) - 1; ++i){
        int t = ts[i];
        int nxt = ts[i + 1];
        for(auto p : m[t]){
            in.insert(p.s);
            en[p.s].push_back(p.idx);
            bit.add(p.s, 1);
        }
        int rem = nxt - t;
        //cout << t << ' ' << rem << '\n';
        int tm = t;
        while(sz(in)){
            //cout << cur << ' ' << tm << '\n';
            in.erase(cur);
            while(sz(en[cur])){
                int id = en[cur].back();
                en[cur].pop_back();
                bit.add(ps[id].s, -1);
                bit.add(ps[id].f, 1);
                ex[ps[id].f].push_back(id);
                in.insert(ps[id].f);
            }
            while(sz(ex[cur])){
                int id = ex[cur].back();
                ex[cur].pop_back();
                bit.add(ps[id].f, -1);
                ans[id] = tm;
            }
            if(!sz(in)) break;
            int Pup, Pdown;
            Pdown = bit.get(cur);
            Pup = bit.get(maxn - 1) - Pdown;
            int nxt;
            if(Pup >= Pdown) nxt = *in.upper_bound(cur);
            else nxt = *prev(in.upper_bound(cur));
            //cout << "going from " << cur << " to ";
            if(abs(cur - nxt) > rem){
                if(nxt < cur) cur -= rem;
                else cur += rem;
                //cout << cur << '\n';
                break;
            }
            rem -= abs(cur - nxt);
            tm += abs(cur - nxt);
            cur = nxt;
            //cout << cur << '\n';
        }
    }
    for(int i = 0 ; i < n ; ++i) cout << ans[i] << '\n';
    return 0;
}