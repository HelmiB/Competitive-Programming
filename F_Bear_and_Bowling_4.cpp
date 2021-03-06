#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

// Keeps upper hull for maximums. 
// add lines with -m and -b and return -ans to 
// make this code work for minimums. 
// source: http://codeforces.com/blog/entry/11155?#comment-162462
#define int     int64_t
#define ii      pair<int,int>
const int is_query = -(1LL<<62);
struct Line {
    int m, b, id;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        int x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct CHT : public multiset<Line> { 
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return 1.0 * (x->b - y->b)*(z->m - y->m) >= 1.0 * (y->b - z->b)*(y->m - x->m);
    }
    void insertLine(int m, int b, int id) {
        auto y = insert({ m, b, id});
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        while (y != begin() && bad(prev(y))) erase(prev(y));
        if(y != begin()) prev(y)->succ = [=] { return &*y; };
    }
    ii eval(int x) {
        auto l = *lower_bound((Line) { x, is_query});
        return {l.m * x + l.b, l.id};
    }
    void merge(CHT &other){
        for(auto &l:other) insertLine(l.m,l.b,l.id);
    }
}cht;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector < int > a(n), s(n), ss(n), pr(n);
    for(auto &x : a) cin >> x;
    s[0] = ss[0] = pr[0] = a[0];
    for(int i = 1 ; i < n ; ++i){
        s[i] = s[i - 1] + a[i];
        ss[i] = ss[i - 1] + s[i];
        pr[i] = pr[i - 1] + (i + 1) * a[i];
    }
    int ans = 0;
    for(int i = n - 1 ; i >= 0 ; --i){
        cht.insertLine(-s[i], pr[i], i);
        ans = max(ans, (i > 1 ? ss[i - 2]:0) + cht.eval(i).first);
    }
    cout << ans << '\n';
    return 0;
}