#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int p[maxn], b[maxn], a[maxn];

struct BIT{
    private: ordered_set < int > tr[maxn + 10];
    public:
    inline void add(int x, long long v){
        for(x++; x < maxn; x += x & -x) tr[x].insert(v);
    }
    inline void rem(int x, long long v){
        for(x++; x < maxn; x += x & -x) tr[x].erase(v);
    }
    inline int get(int x, int l, int r){
        int ret = 0;
         for(x++; x; x -= x & -x)
             ret += sz(tr[x]) - tr[x].order_of_key(r + 1) +  tr[x].order_of_key(l);
        return ret;
    }
    inline int range(int l, int r, int a, int b){
        return get(r, a, b) - (l ? get(l - 1, a, b):0);
    }
}bit;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i){
        cin >> a[i];
        --a[i];
        p[a[i]] = i;
    }
    for(int i = 0 ; i < n ; ++i){
        cin >> b[i];
        --b[i];
        bit.add(p[b[i]], i);
    }
    while(m--){
        int t;
        cin >> t;
        if(t == 1){
            int la, lb, ra, rb;
            cin >> la >> ra >> lb >> rb;
            --la; --lb; --ra; --rb;
            cout << ra - la + 1 - bit.range(la, ra, lb, rb) << '\n';
        }else{
            int x, y;
            cin >> x >> y;
            --x; --y;
            bit.rem(p[b[x]], x);
            bit.rem(p[b[y]], y);
            swap(b[x], b[y]);
            bit.add(p[b[x]], x);
            bit.add(p[b[y]], y);
        }
    }
    return 0;
}