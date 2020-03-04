#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1500;
const int mod = 1e9 + 7;
bool done[maxn];
vector < int > ls[2 * maxn * maxn], rs[2 * maxn * maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        int l, r;
        cin >> l >> r;
        l += maxn * maxn;
        r += maxn * maxn;
        if(l > r) swap(l, r);
        ls[l].push_back(i);
        rs[r].push_back(i);
    }
    vector < int > ans;
    set < int > in;
    for(int i = 0 ; i < 2 * maxn * maxn ; ++i){
        for(auto l : ls[i]) in.insert(l);
        bool ok = false;
        for(auto r : rs[i]){
            in.erase(r);
            if(!done[r]) ok = true;
        }
        if(ok){
            for(auto x : in) done[x] = true;
            ans.push_back(i - maxn * maxn);
        }
    }
    cout << sz(ans) << '\n';
    for(auto x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}
