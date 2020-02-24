#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 100500;
const int mod = 1e9 + 7;


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        map < long long , long long > org, can;
        for(int i = 0 ; i < m ; ++i){
            int x;
            cin >> x;
            org[x]++;
            can[x]++;
        }
        for(int i = 1 ; i <= 59 ; ++i)
            can[(1ll << i)] += can[(1ll << (i - 1))] / 2;
        int ans = 0;
        bool flag = false;
        for(int j = 0 ; j <= 59 && !flag; ++j)
            if(n & (1ll << j)){
                if(can[1ll << j]){
                    long long need = 1;
                    int k = j;
                    while(true){
                        if(org[1ll << k] >= need){
                            org[1ll << k] -= need;
                            can.clear();
                            for(auto x : org) can[x.first] = x.second;
                            for(int i = 1 ; i <= 59 ; ++i)
                            can[(1ll << i)] += can[(1ll << (i - 1))] / 2;
                            break;
                        }else if(org[1ll << k]){
                            need -= org[1ll << k];
                            org[1ll << k] = 0;
                        }
                        need *= 2;
                        k--;
                    }
                }else{
                    int ad = 0;
                    int k = j;
                    while(true){
                        if(k == 60){
                            flag = true;
                            break;
                        }
                        if(org[1ll << k]){
                            org[1ll << k]--;
                            can.clear();
                            for(auto x : org) can[x.first] = x.second;
                            for(int i = 1 ; i <= 59 ; ++i)
                            can[(1ll << i)] += can[(1ll << (i - 1))] / 2;
                            break;
                        } else org[1ll << k]++;
                        ad++;
                        k++;
                    }
                   // cout << j << ' ' << k << ' ' << ad << '\n';
                    ans += ad;
                }
            }
        if(flag) cout << -1 << '\n';
        else cout << ans << '\n'; 
    }

    return 0;
}
