#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
map < int, vector < int > > pr;
int a[maxn], idx[maxn];
vector < pair < int, int > > dv[maxn];
map < int, int > done;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;  
    for(int i = 0 ; i < n ; ++i) cin >> a[i];    
    map < int, int > ks;
    for(int i = 2 ; i * i <= k ; ++i)
        while(k % i == 0){
            ks[i]++;
            k /= i;
        }
    if(k > 1) ks[k] = 1;
    for(int i = n - 1 ; i >= 0 ; --i){
        int x = a[i];
        if(done.count(x)){
            idx[i] = done[x];
            for(auto d : dv[idx[i]]){
                auto &u = pr[d.first];
                while(d.second--) u.push_back(i);
            }
            continue;
        }
        idx[i] = i;
        done[x] = i;
        for(int j = 2 ; j * j <= x ; ++j){
            int ad = 0;
            while(x % j == 0) ad++, x /= j;
            if(ad){
                dv[i].push_back({j, ad});
                auto &u = pr[j];
                while(ad--) u.push_back(i);
            }
        }
        if(x > 1) pr[x].push_back(i), dv[i].push_back({x, 1});
    }
    long long ans = 0;
    for(int i = 0 ; i < n ; ++i){
        int r = i;
        bool flag = true;
        for(auto p : ks){
            if(sz(pr[p.first]) < p.second){
                flag = false;
                break;
            }
            r = max(r, pr[p.first][sz(pr[p.first]) - p.second]);
        }
        if(!flag) break;
        ans += n - r;
        for(auto d : dv[idx[i]]){
            auto &u = pr[d.first];
            while(d.second--) u.pop_back();
        }
    }
    cout << ans << '\n';
    return 0;
}