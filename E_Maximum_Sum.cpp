#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[20], F[1 << 16], dp[1 << 16];
vector < int > masks;
int n;

void build(){
    for(int i = 0; i < (1 << n); ++i) F[i] = dp[i];
    for(int i = 0; i < n; ++i) 
        for(int mask = 0; mask < (1 << n); ++mask)
            if(mask & (1<<i))
                F[mask] = max(F[mask], F[mask^(1<<i)]);
}

void init(){
    masks.clear();
    for(int i = 0 ; i < (1ll << n); ++i) dp[i] = 0;
    for(int mask = 0 ; mask < (1ll << n); ++mask){
        bool can = true;
        for(int i = 0 ; i < n - 1 ; ++i){
            bool on1 = ((1 << i) & mask);
            bool on2 = ((1 << (i + 1)) & mask);
            if(on1 && on2){
                can = false;
                break;
            }
        }
        if(can) masks.push_back(mask);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        init();
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < n ; ++j) cin >> a[j];
            build();
            for(int j = 0 ; j < (1 << n) ; ++j) dp[j] = 0;
            for(auto mask : masks){
                long long sm = 0;
                int need = (1 << n) - 1;
                for(int j = 0 ; j < n ; ++j)
                    if((1 << j) & mask){
                        sm += a[j];
                        need &=~(1 << j);
                        if(j) need &=~(1 << (j - 1));
                        if(j != n - 1) need &=~(1 << (j + 1));
                    }
                dp[mask] = sm + F[need];
            }
        }
        for(int i = 0 ; i < (1 << n) - 1; ++i) dp[i + 1] = max(dp[i + 1], dp[i]);
        cout << dp[(1 << n) - 1] << '\n';
    }

    return 0;
}
