#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
map < int , vector < int > > pos;
vector < int > ls[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
    for(auto v : pos){
        if(sz(v.second) < k) continue;
        int l = 0, r = k - 1;
        while(r < sz(v.second)){
            ls[v.second[l]].push_back(v.second[r]);
            l++; r++;
        }
    }
    long long ans = 0;
    int min_r = n;
    for(int i = n - 1 ; i >= 0 ; --i){
        for(auto r : ls[i]) min_r = min(min_r, r);
        if(min_r == n) continue;
        ans += n - min_r;
    }
    cout << ans << '\n';
    return 0;
}
