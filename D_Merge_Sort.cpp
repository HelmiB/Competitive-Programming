#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[maxn], k;

int calc(int l, int r){
    bool sorted = true;
    for(int i = l ; i < r - 1; ++ i)
        if(a[i] > a[i + 1])
            sorted = false;
    if(sorted) return 1;
    return 1 + calc(l, (l + r) / 2) + calc((l + r) / 2, r);
}

vector < int > rem;
int op = 0;

void solve(int l, int r){
    if(l == r) return;
    if(k < 0) return;
    if(k == 0){
        for(int i = r - 1 ; i >= l ; --i){
            a[i] = rem.back();
            rem.pop_back();
        }
        return;
    }
    if(2 * (r - l - 1) <= k){
        for(int i = l ; i < r ; ++i){
            a[i] = rem.back();
            rem.pop_back();
        }
        k -= 2 * (r - l - 1);
        return;
    }
    k -= 2;
    solve(l, (l + r) / 2);
    solve((l + r) / 2, r);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n >> k;
    int prv = k;
    --k;
    for(int i = 1 ; i <= n ; ++i) rem.push_back(i);
    solve(0, n);
    if(k != 0) return cout << -1 << '\n', 0;
    assert(calc(0, n) == prv);
    for(int i = 0 ; i < n ; ++i) cout << a[i] << ' ';
    cout << '\n';
    return 0;
}