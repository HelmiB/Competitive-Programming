#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 300500;
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
};

bool in[maxn];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector < pair < int, pair < int, int > > > q(n);
    for(auto &x : q){
        cin >> x.first >> x.second.first;
        if(x.first == 1) cin >> x.second.second;
        if(x.first == 2) x.second.first--;
    }
    set < int > in;
    int sq = 2500;
    for(int i = 0 ; i < n ; i += sq){
        CHT cht;
        set < int > tmp;
        for(int j = i ; j < min(i + sq, n) ; ++j)
            if(q[j].first == 2 && in.find(q[j].second.first) != in.end()){
                tmp.insert(q[j].second.first);
                in.erase(q[j].second.first);
            }
        for(auto j : in) cht.insertLine(q[j].second.first, q[j].second.second, j);
        for(int j = i ; j < min(i + sq, n) ; ++j){
            int t = q[j].first;
            if(t == 1) tmp.insert(j);
            if(t == 2) tmp.erase(q[j].second.first);
            if(t == 3){
                if(!sz(in) && !sz(tmp)) cout << "EMPTY SET\n";
                else{
                    long long ans = (sz(in) ? cht.eval(q[j].second.first).first:is_query);
                    for(auto k : tmp) ans = max(ans, q[k].second.first * q[j].second.first + q[k].second.second);
                    cout << ans << '\n';
                }
            }
        }
        for(auto j : tmp) in.insert(j);
    }
    return 0;
}