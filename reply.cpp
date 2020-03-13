#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 300;
char a[MAXN][MAXN];
int res[MAXN][MAXN];
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


pair < int, int > mpos[MAXN * MAXN], dpos[MAXN * MAXN];
int w, h, nd, nm;
int cur = 1;
map<string,int> id;
struct Developer {
    string c;
    LL b;
    int n;
    bitset<500> s;
};
struct Manager {
    string c;
    LL b;
};
Developer dev[MAXN * MAXN] ;
Manager man[MAXN * MAXN];
LL wp (Developer &a, Developer &b){
    LL  un = a.s.count() + b.s.count();
    bitset<500> c = a.s & b.s;
    LL inter = c.count();
    return inter  * (un - 2LL * inter);
}


LL score(){
    LL ans = 0;
    for(int i = 0 ; i < h - 1 ; ++i)
        for(int j = 0 ; j < w - 1; ++j)
            if(a[i][j] == '_'){ 
                if(a[i + 1][j] == '_') ans += wp(dev[res[i][j]], dev[res[i + 1][j]]) + (dev[res[i][j]].c == dev[res[i + 1][j]].c) *  dev[res[i][j]].b * dev[res[i + 1][j]].b;
                else if(a[i + 1][j] == 'M') ans += (dev[res[i][j]].c == man[res[i + 1][j]].c) *  dev[res[i][j]].b * man[res[i + 1][j]].b;
                if(a[i][j + 1] == '_') ans += wp(dev[res[i][j]], dev[res[i][j + 1]]) + (dev[res[i][j + 1]].c == dev[res[i][j + 1]].c) *  dev[res[i][j + 1]].b * dev[res[i][j + 1]].b;
                else if(a[i][j + 1] == 'M') ans += (dev[res[i][j + 1]].c == man[res[i][j + 1]].c) *  dev[res[i][j + 1]].b * man[res[i][j + 1]].b;
            
            }else if(a[i][j] == 'M'){
                if(a[i + 1][j] == '_') ans += (man[res[i][j]].c == dev[res[i + 1][j]].c) *  man[res[i][j]].b * dev[res[i + 1][j]].b;
                else if(a[i + 1][j] == 'M') ans += (man[res[i][j]].c == man[res[i + 1][j]].c) *  man[res[i][j]].b * man[res[i + 1][j]].b;
                if(a[i][j + 1] == '_') ans += (man[res[i][j + 1]].c == dev[res[i][j + 1]].c) *  man[res[i][j + 1]].b * dev[res[i][j + 1]].b;
                else if(a[i][j + 1] == 'M') ans += (man[res[i][j + 1]].c == man[res[i][j + 1]].c) *  man[res[i][j + 1]].b * man[res[i][j + 1]].b;
            }
        for(int j = 0 ; j < w - 1; ++j) 
            if(a[h - 1][j] == '_'){
                if(a[h - 1][j + 1] == '_') ans += wp(dev[res[h - 1][j]], dev[res[h - 1][j + 1]]) + (dev[res[h - 1][j + 1]].c == dev[res[h - 1][j + 1]].c) *  dev[res[h - 1][j + 1]].b * dev[res[h - 1][j + 1]].b;
                else if(a[h - 1][j + 1] == 'M') ans += (dev[res[h - 1][j + 1]].c == man[res[h - 1][j + 1]].c) *  dev[res[h - 1][j + 1]].b * man[res[h - 1][j + 1]].b;
            }else if(a[h - 1][j] == 'M'){
                if(a[h - 1][j + 1] == '_') ans += (man[res[h - 1][j + 1]].c == dev[res[h - 1][j + 1]].c) *  man[res[h - 1][j + 1]].b * dev[res[h - 1][j + 1]].b;
                else if(a[h - 1][j + 1] == 'M') ans += (man[res[h - 1][j + 1]].c == man[res[h - 1][j + 1]].c) *  man[res[h - 1][j + 1]].b * man[res[h - 1][j + 1]].b;
            }
    return ans;
}


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

LL solve(){
    ordered_set<int> dset, mset;
    for(int i = 0 ; i < h ; ++i)
        for(int j = 0 ; j < w ; ++j)
            res[i][j] = MAXN * MAXN - 1;
    for(int i = 0 ; i < nd ; ++i) dset.insert(i);
    for(int i = 0 ; i < nm ; ++i) mset.insert(i);
    for(int i = 0 ; i < h - 1; ++i)
        for(int j = 0 ; j < w - 1; ++j)
            if(a[i][j] == '_'){
                if(res[i][j] == MAXN * MAXN - 1){
                    if((int)dset.size() == 0) continue;
                    int idx = *dset.find_by_order(uniform_int_distribution<int>(0, sz(dset) - 1)(rng));
                    res[i][j] = idx;
                    dset.erase(res[i][j]);
                }
                if(a[i + 1][j] == '_' && res[i + 1][j] == MAXN * MAXN - 1){
                    int bst = -1, id = -1;
                    for(auto v : dset){
                        int sm = wp(dev[res[i][j]], dev[v]) + (dev[res[i][j]].c == dev[v].c) *  dev[res[i][j]].b * dev[v].b;
                        if(sm > bst) id = v, bst = sm;
                    }
                    if(~id){
                        res[i + 1][j] = id;
                        dset.erase(id);
                    }
                }
                else if(a[i + 1][j] == 'M' && res[i + 1][j] == MAXN * MAXN - 1){
                    int bst = -1, id = -1;
                    for(auto v : mset){
                        int sm = (dev[res[i][j]].c == man[v].c) *  dev[res[i][j]].b * man[v].b;
                        if(sm > bst) id = v, bst = sm;
                    }
                    if(~id){
                        res[i + 1][j] = id;
                        mset.erase(id);
                    }
                }
                if(a[i][j + 1] == '_' && res[i][j + 1] == MAXN * MAXN - 1){
                    int bst = -1, id = -1;
                    for(auto v : dset){
                        int sm = wp(dev[res[i][j]], dev[v]) + (dev[res[i][j]].c == dev[v].c) *  dev[res[i][j + 1]].b * dev[v].b;
                        if(sm > bst) id = v, bst = sm;
                    }
                    if(~id){
                        res[i][j + 1] = id;
                        dset.erase(id);
                    }
                }
                else if(a[i][j + 1] == 'M' && res[i][j + 1] == MAXN * MAXN - 1){
                    int bst = -1, id = -1;
                    for(auto v : mset){
                        int sm = (dev[res[i][j]].c == man[v].c) *  dev[res[i][j]].b * man[v].b;
                        if(sm > bst) id = v, bst = sm;
                    }
                    if(~id){
                        res[i][j + 1] = id;
                        mset.erase(id);
                    }
                }
            }else if(a[i][j] == 'M'){
                if(res[i][j] == MAXN * MAXN - 1){
                    if((int)mset.size() == 0) continue;
                    int idx = *mset.find_by_order(uniform_int_distribution<int>(0, sz(mset) - 1)(rng));
                    mset.erase(idx);
                    res[i][j] = idx;
                }
                if(a[i + 1][j] == '_' && res[i + 1][j] == MAXN * MAXN - 1){
                    int bst = -1, id = -1;
                    for(auto v : dset){
                        int sm = (man[res[i][j]].c == dev[v].c) *  man[res[i][j]].b * dev[v].b;
                        if(sm > bst) id = v, bst = sm;
                    }
                    if(~id){
                        res[i + 1][j] = id;
                        dset.erase(id);
                    }
                }
                else if(a[i + 1][j] == 'M' && res[i + 1][j] == MAXN * MAXN - 1){
                    int bst = -1, id = -1;
                    for(auto v : mset){
                        int sm = (man[res[i][j]].c == man[v].c) *  man[res[i][j]].b * man[v].b;
                        if(sm > bst) id = v, bst = sm;
                    }
                    if(~id){
                        res[i + 1][j] = id;
                        mset.erase(id);
                    }
                }
                if(a[i][j + 1] == '_' && res[i][j + 1] == MAXN * MAXN - 1){
                    int bst = -1, id = -1;
                    for(auto v : dset){
                        int sm = (man[res[i][j]].c == dev[v].c) *  man[res[i][j]].b * dev[v].b;
                        if(sm > bst) id = v, bst = sm;
                    }
                    if(~id){
                        res[i][j + 1] = id;
                        dset.erase(id);
                    }
                }
                else if(a[i][j + 1] == 'M' && res[i][j + 1] == MAXN * MAXN - 1){
                    int bst = -1, id = -1;
                    for(auto v : mset){
                        int sm = (man[res[i][j]].c == man[v].c) *  man[res[i][j]].b * man[v].b;
                        if(sm > bst) id = v, bst = sm;
                    }
                    if(~id){
                        res[i][j + 1] = id;
                        mset.erase(id);
                    }
                }
            }
        for(int j = 0 ; j < w - 1; ++j) 
            if(a[h - 1][j] == '_'){
                if(res[h - 1][j] == MAXN * MAXN - 1){
                    if((int)dset.size() == 0) continue;
                    int idx = *dset.find_by_order(uniform_int_distribution<int>(0, sz(dset) - 1)(rng));
                    res[h - 1][j] = idx;
                    dset.erase(res[h - 1][j]);
                }
                if(a[h - 1][j + 1] == '_' && res[h - 1][j + 1] == MAXN * MAXN - 1){
                    int bst = -1, id = -1;
                    for(auto v : dset){
                        int sm = wp(dev[res[h - 1][j + 1]], dev[v]) + (dev[res[h - 1][j + 1]].c == dev[v].c) *  dev[res[h - 1][j + 1]].b * dev[v].b;
                        if(sm > bst) id = v, bst = sm;
                    }
                    if(~id){
                        res[h - 1][j + 1] = id;
                        dset.erase(id);
                    }
                }
                else if(a[h - 1][j + 1] == 'M' && res[h - 1][j + 1] == MAXN * MAXN - 1){
                    int bst = -1, id = -1;
                    for(auto v : mset){
                        int sm = (dev[res[h - 1][j + 1]].c == man[v].c) *  dev[res[h - 1][j + 1]].b * man[v].b;
                        if(sm > bst) id = v, bst = sm;
                    }
                    if(~id){
                        res[h - 1][j + 1] = id;
                        mset.erase(id);
                    }
                }
                
            }else if(a[h - 1][j] == 'M'){
                if(res[h - 1][j] == MAXN * MAXN - 1){
                    if((int)mset.size() == 0) continue;
                    int idx = *mset.find_by_order(uniform_int_distribution<int>(0, sz(mset) - 1)(rng));
                    mset.erase(idx);
                    res[h - 1][j] = idx;
                }
                if(a[h - 1][j + 1] == '_' && res[h - 1][j + 1] == MAXN * MAXN - 1){
                    int bst = -1, id = -1;
                    for(auto v : dset){
                        int sm = (man[res[h - 1][j + 1]].c == dev[v].c) *  man[res[h - 1][j + 1]].b * dev[v].b;
                        if(sm > bst) id = v, bst = sm;
                    }
                    if(~id){
                        res[h - 1][j + 1] = id;
                        dset.erase(id);
                    }
                }
                else if(a[h - 1][j + 1] == 'M' && res[h - 1][j + 1] == MAXN * MAXN - 1){
                    int bst = -1, id = -1;
                    for(auto v : mset){
                        int sm = (man[res[h - 1][j + 1]].c == man[v].c) *  man[res[h - 1][j + 1]].b * man[v].b;
                        if(sm > bst) id = v, bst = sm;
                    }
                    if(~id){
                        res[h - 1][j + 1] = id;
                        mset.erase(id);
                    }
                }}
    return score();
}

void get_config(){
    for(int i = 0 ; i < nd ; ++i) dpos[i] = {-1, -1};
    for(int i = 0 ; i < nm ; ++i) mpos[i] = {-1, -1};
    for(int i = 0 ; i < h ; ++i)
        for(int j = 0 ; j < w ; ++j)
            if(a[i][j] == '_') dpos[res[i][j]] = {i, j};
            else if(a[i][j] == 'M') mpos[res[i][j]] = {i, j};
}

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> w >> h;
    for (int i  = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> a[i][j];
    cin >> nd;
    for (int i = 0; i < nd; i++){
            cin >> dev[i].c >> dev[i].b >> dev[i].n;
            for (int j = 0; j < dev[i].n; j++){
                string x;
                cin >> x;
                if (!id[x]){
                    id[x] = cur;
                    cur++;
                }
                dev[i].s[id[x]] = 1;
            }
    }
    cin >> nm;
    for (int i = 0; i < nm; i++) cin >> man[i].c >> man[i].b;
    set < int > done;
    LL ans = 0;
    do{
        LL sm = ans;
        ans = max(ans, solve());
        if(ans > sm && ans > 5e5) get_config(); 
        if(1.0 * (double) clock() / CLOCKS_PER_SEC - 1200 > 1e-9) break;
    }while(ans < 6e5);
    for(int i = 0 ; i < nd ; ++i)
        if(~dpos[i].first) cout << dpos[i].second << ' ' << dpos[i].first << '\n';
        else cout << 'X' << '\n';
    for(int i = 0 ; i < nm ; ++i)
        if(~mpos[i].first) cout << mpos[i].second << ' ' << mpos[i].first  << '\n';
        else cout << 'X' << '\n';
}