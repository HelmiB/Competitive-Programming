#include<bits/stdc++.h>
using namespace std;
const int maxn = 100500;
const int mod = 1e9 + 7;

struct BIT{
    private: long long tree[maxn + 10];
    public:
    void add(int x, long long v = 1){for(x++; x < maxn; x += x & -x)tree[x] += v;}
    long long get(int x){long long ret = 0; for(x++; x; x -= x & -x)ret += tree[x]; return ret;}
 
}bit[4]; // 0 min x 1 max x 2 min y 3 max y


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int d, n, m;
    cin >> d >> n >> m;
    vector < pair < pair < int, int > , pair < int , int > > > p;
    for(int i = 0 ; i < d ; ++i){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        p.push_back({{x, y},{a, b}});
        bit[0].add(min(x, a));
        bit[1].add(max(x, a));
        bit[2].add(min(y, b));
        bit[3].add(max(y, b));
    }
    int l, r, t, b;
    cin >> l >> r >> t >> b;
    for(int i = 0 ; i < d ; ++i){
        int li = bit[0].get(max(p[i].first.first, p[i].second.first) - 1), ri = bit[1].get(maxn) - bit[1].get(min(p[i].first.first, p[i].second.first)),
            ti = bit[2].get(max(p[i].first.second, p[i].second.second) - 1), bi = bit[3].get(maxn) - bit[3].get(min(p[i].first.second, p[i].second.second));
        if(abs(p[i].first.first - p[i].second.first) >= 1) li--, ri--;
        if(abs(p[i].first.second - p[i].second.second) >= 1) ti--, bi--;
        if(l == li && r == ri && t == ti && b == bi) return cout << i + 1 << '\n', 0;
    }
    cout << -1 << '\n';
    return 0;
}
