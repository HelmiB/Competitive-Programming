#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
struct node{
    long double pr, ps, pp;
    bool vis;
    node(){
        pr = ps = pp = vis = 0;
    }
};
node dp[101][101][101];

void update(node &x, long double pr){
    x.pp *= pr;
    x.pr *= pr;
    x.ps *= pr;
}

void add(node &a, node b){
    a.pr += b.pr;
    a.ps += b.ps;
    a.pp += b.pp;
}

node solve(int r, int s, int p){
    int n = r + s + p;
    node ans;
    if(!n) return ans;
    if(r == n){
        ans.pr = 1;
        return ans;
    }
    if(s == n){
        ans.ps = 1;
        return ans;
    }
    if(p == n){
        ans.pp = 1;
        return ans;
    }
    node & ret = dp[r][s][p];
    if(ret.vis) return ret;
    ret.vis = true;
    int tot = n * (n - 1) - (r * (r - 1) + s * (s - 1) + p * (p - 1));
    tot /= 2;
    assert(tot > 0);
    if(r && s){
        node f = solve(r, s - 1, p);
        update(f, (long double) (r * s) / tot);
        add(ret, f);
    }
    if(r && p){
        node f = solve(r - 1, s, p);
        update(f, (long double) (p * r) / tot);
        add(ret, f);
    }
    if(p && s){
        node f = solve(r, s, p - 1);
        update(f, (long double) (p * s) / tot);
        add(ret, f);
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int r, s, p;
    cin >> r >> s >> p;
    auto ans = solve(r, s, p);
    cout << fixed << setprecision(12) << ans.pr << ' ' << ans.ps << ' ' << ans.pp << '\n';
    return 0;
}