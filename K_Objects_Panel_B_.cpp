#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 300500;
const int mod = 1e9 + 7;
int in[maxn], out[maxn];
bool state[maxn];
vector < int > g[maxn];
int cur;

void init(int u = 0){
    in[u] = cur++;
    for(auto v : g[u])
        init(v);
    out[u] = cur - 1;
}

struct BIT{
    private: long long tree[maxn + 10];
    public:
    void add(int x, long long v){for(x++; x < maxn; x += x & -x)tree[x] += v;}
    long long get(int x){long long ret = 0; for(x++; x; x -= x & -x)ret += tree[x]; return ret;}
 
}bit;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1 ; i <= n ; ++i){
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    init();
    memset(state, true, sizeof state);
    for(int i = 0 ; i <= n ; ++i) bit.add(in[i], 1);
    while (q--){
        int x;
        cin >> x;
        if(state[x]){
            int cnt = bit.get(out[x]) - (in[x] ? bit.get(in[x] - 1):0);
            bit.add(in[x], 1 - cnt);
        }else{  
            int cnt = bit.get(in[x]) - (in[x] ? bit.get(in[x] - 1):0);
            bit.add(in[x], 1 - cnt);
        }
        state[x] = 1 - state[x];
        cout << bit.get(maxn) << ' ';
    }
    cout << '\n';
    return 0;
}