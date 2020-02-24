#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(l, r)(rng); [l, r]

#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int p[1010], n, x, y;
int cnt = 0;
int res[3000], sz;

bool ask(set < int > s){
    //if(cnt == 19) exit(0);
    int xr = 0;
    for(auto x : s) xr ^= res[x];
    cnt++;
    cout << cnt << '\n';
    return (xr == y) || ((xr ^ x) == y);
    cout << "? " << sz(s) << ' ';
    for(auto x : s) cout << x << ' ';
    cout << '\n';
    cout << flush;
    int r;
    cin >> r;
    cnt++;
    return (r == y) || ((r ^ x) == y);
}

int get(vector < int > v){
    for(int i = 0; i < 500 ; ++i) shuffle(all(v), rng);
    int lo = 0, hi = sz(v) - 1;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        set < int > s;
        for(int i = lo ; i <= mid ; ++i) s.insert(v[i]);
        if(ask(s)) hi = mid - 1;
        else lo = mid + 1;
    }
    assert(hi < sz(v) - 1);
    return v[hi + 1];
}

void init(){
    n = 712, x = 3, y = 5;
    for(int i = 1 ; i <= n ; ++i) res[i] = x;
    res[255] = res[511] = y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin >> n >> x >> y;
    init();
    set < int > s;
    int cst = 7;
    while(!sz){
        sz = n / cst;
        cst--;
    }
    vector < set < int > > log;
    while(true){
        s.clear();
        while(sz(s) != sz){
            int x = uniform_int_distribution<int>(1, n)(rng);
            if(s.find(x) == s.end()) s.insert(x);
        }
        if(ask(s)){
            vector < int > tmp1;
            for(auto x : s) tmp1.push_back(x);
            int p1 = get(tmp1);
            cout << " ----------\n ";
            for(auto &l : log)
                if(l.find(p1) != l.end()){
                    l.erase(p1);
                    vector < int > tmp;
                    for(auto x : l) tmp.push_back(x);
                    int p2 = get(tmp);
                    cout << "! " << min(p1, p2) << ' ' << max(p1, p2) << '\n';
                    cout << flush;
                    return 0;
                }
            log.push_back(s);
            set < int > in;
            for(int i = 1 ; i <= n ; ++i) in.insert(i);
            for(auto l : log)
                for(auto x : l)
                    in.erase(x);
            vector < int > tmp;
            for(auto x : in) tmp.push_back(x);
            cout << "sz = " << sz(tmp) << '\n';
            int p2 = get(tmp);
            cout << "! " << min(p1, p2) << ' ' << max(p1, p2) << '\n';
            cout << flush;
            return 0;
        }
        log.push_back(s);
    }
    return 0;
}
