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
    vector < long long > gold;
    long long x, y, l, r;
    cin >> x >> y >> l >> r;
    gold.push_back(l - 1);
    gold.push_back(r + 1);
    long long pa = 1;
    while(pa <= r){
        long long pb = 1;
        while(pb <= r - pa){
            if(pa + pb >= l) gold.push_back(pa + pb);
            if(pb > (r - pa) / y) break;
            pb *= y;

        }
        if(pa > r / x) break;
        pa *= x;
    }
    sort(all(gold));
    gold.erase(unique(all(gold)), gold.end());
    long long ans = 0;
    for(int i = 0 ; i < sz(gold) - 1 ; ++i) ans = max(ans, gold[i + 1] - gold[i] - 1);
    cout << ans << '\n';
    return 0;
}