#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
vector < pair < int, int > > v;
long long cntp[maxn], cnts[maxn], costp[maxn], costs[maxn];


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector < int > a(n);
    for(auto &x : a) cin >> x;
    sort(all(a));
    for(int i = 0 ; i < n ; ++i){
        int j = i;
        while(j < n && a[j] == a[i]) ++j;
        v.push_back({a[i], j - i});
        i = j - 1;
    }
    n = sz(v);
    cntp[0] = v[0].second; cnts[n - 1] = v[n - 1].second;
    for(int i = 1 ; i < n ; ++i){
        cntp[i] = cntp[i - 1] + v[i].second;
        costp[i] = costp[i - 1] + cntp[i - 1] * (v[i].first - v[i - 1].first);
    }
    for(int i = n - 2 ; i >= 0 ; --i){
        cnts[i] = v[i].second + cnts[i + 1];
        costs[i] = costs[i + 1] + cnts[i + 1] * (v[i + 1].first - v[i].first);
    }
    long long ans = 1e18;
    for(int i = 0 ; i < n ; ++i){
        long long adp = (i ? cntp[i - 1]:0), smp = (i ? costp[i - 1]:0);
        long long ads = cnts[i + 1], sms = costs[i + 1];
        int need = k - v[i].second;
        if(adp) smp += adp * (v[i].first - 1 - v[i - 1].first);
        if(ads) sms += ads * (v[i + 1].first - v[i].first - 1);
        if(need <= 0){
            ans = 0;
            break;
        }
        long long tm = 1e18;
        if(adp >= need) tm = smp + need ;
        if(ads >= need) tm = min(tm, sms + need);
        if(ads < need && adp < need && ads + adp >= need){
            long long tmp = sms + smp;
            if((v[i].first - v[i - 1].first) < (v[i + 1].first - v[i].first)){
                tmp += adp ;
                need -= adp;
                tmp += need;
            }else{
                tmp += ads;
                need -= ads;
                tmp += need ;
            }
            tm = min(tm, tmp);
        }
        ans = min(ans, tm); 
    }
    cout << ans << '\n';
    return 0;
}