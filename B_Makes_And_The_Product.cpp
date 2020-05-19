#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    map < int, long long > cnt;
    int n;
    cin >> n;
    vector < int > a(n);
    for(auto &x : a){
        cin >> x;
        cnt[x]++;
    }
    sort(all(a));
    int x = a[0], y = a[1], z = a[2];
    long long ans = 0;
    if(x != y && y != z){
        ans = cnt[x] * cnt[y] * cnt[z];
    }
    if(x == y && y == z){
        ans = (cnt[x] - 1) * (cnt[x] - 2) * cnt[x] / 6;
    }else if(x == y){
        ans = cnt[z] * cnt[x] * (cnt[x] - 1) / 2;
    }else if(y == z){
        ans = cnt[x] * cnt[y] * (cnt[y] - 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}