#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int cnt[100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long u, v;
    cin >> u >> v;
    for(int i = 59 ; i >= 0 ; --i)
        if(v & (1ll << i))
            cnt[i] = 1;
    bool can = true;

    for(int i = 59 ; i >= 0 ; --i)
        if(u & (1ll << i)){
            if(!cnt[i]){
                for(int j = i + 1 ; j <= 59 ; ++j)
                    if(cnt[j] >= 2){
                        cnt[j] -= 2;
                        for(int k = i + 1 ; k < j ; ++k)
                            cnt[k] += 2;
                        cnt[i] += 4;
                        break;
                    }
            }
            if(!cnt[i]) can = false;
            if(cnt[i] % 2 == 0) cnt[i - 1] += 2, cnt[i]--;
        }else{
            if(cnt[i] % 2){
                if(!i) can = false;
                else{
                    cnt[i - 1] += 2;
                    cnt[i]--;
                }
            }
        }
    if(!can) return cout << -1 << '\n', 0;
    vector < long long > vec;
    long long vs = 0, vx = 0;
    while(1){
        long long el = 0;
        for(int i = 0 ; i < 60 ; ++i)
            if(cnt[i]){
                el += (1ll << i);
                cnt[i]--;
            }
        if(!el) break;
        vs += el;
        vx ^= el;
        vec.push_back(el);
    }
    assert(vx == u && vs == v);
    cout << sz(vec) << '\n';
    for(auto x : vec) cout << x << ' ';
    cout << '\n';
    return 0;
}
