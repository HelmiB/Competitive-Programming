#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

int trans(vector < int > v){
    if(v[0] == -1) return -1;
    int ans = v[0];
    bool side = false;
    for(int i = 1 ; i < sz(v) ; ++i){
        if(v[i] < v[i - 1]) side = true;
        int pw = (int)log2(v[i]);
        if(side) ans += (1 << (30 - pw));
        else ans += (1 << pw);
    }
    return ans;
}

vector < int > rev(int x){
    vector < int > res;
    if(x == -1){
        res.push_back(-1);
        return res;
    }
    bitset < 31 > b(x);
    int prv = b._Find_next(-1);
    while(prv < b.size()){
        if(prv >= 14) res.push_back(1 << (30 - prv));
        else res.push_back(1 << prv);
        prv = b._Find_next(prv);
    }
    
    return res;
}

int addL(int st , int x){
    if(!st) return x;
    vector < int > rs; rs.push_back(x);
    vector < int > state = rev(st);
    bool sm = false;
    for(auto x : state){
        if(x == rs.back()){
            rs[sz(rs) - 1] += x;
            continue;
        }
        if(x > rs.back() && sm) return -1;
        if(x < rs.back()) sm = true;
        rs.push_back(x);
    }
    return trans(rs);
}

int addR(int st , int x){
    if(!st) return x;
    vector < int > rs; rs.push_back(x);
    vector < int > state = rev(st);
    reverse(all(state));
    bool sm = false;
    for(auto x : state){
        if(x == rs.back()){
            rs[sz(rs) - 1] += x;
            continue;
        }
        if(x > rs.back() && sm) return -1;
        if(x < rs.back()) sm = true;
        rs.push_back(x);
    }
    reverse(all(rs));
    return trans(rs);
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector < int > v(n);
        for(auto &x : v) cin >> x;
        unordered_map < int , int > anc;
        vector < int > in;
        in.push_back(0);
        for(auto x : v){
            vector < int > rs;
            for(auto y : in){
                auto ansL = addL(y, x);
                auto ansR = addR(y, x);
                if(~ansL){
                    anc[ansL] = y;
                    rs.push_back(ansL);
                }
                if(~ansR){
                    anc[ansR] = y;
                    rs.push_back(ansR);
                }
            }
            in = rs;
        }
        int ans = 0;
        for(auto x : in)
            if(__builtin_popcountll(x) == 1){
                ans = x;
                break;
            }
        if(!ans){
            cout << "no\n";
            continue;
        }
        string res = "";
        while(sz(v)){
            int x = v.back();
            v.pop_back();
            auto par = anc[ans];
            if(addL(par, x) == ans) res += "l";
            else res += "r";
            ans = par;
        }
        reverse(all(res));
        cout << res << '\n';
    }

    return 0;
}