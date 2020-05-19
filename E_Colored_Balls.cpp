#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < int > a;

long long solve1(int x){
    long long ad = 0;
    for(auto f : a){
        long long cnt = (f + x) / (x + 1);
        if(x * 1LL * cnt > f) return 1e18;
        ad += cnt;
    }
    return ad;
}


long long solve2(int k){
    int x = a[0] / k;
    return min(solve1(x), solve1(x - 1));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    for(auto &x : a) cin >> x;
    sort(all(a));
    long long ans = 1e18;
    for(int j = 1 ; j * j <= a[0] ; ++j){
        ans = min(ans, solve1(j));
        ans = min(ans, solve2(j));
    }
    cout << ans << '\n';
    return 0;
}