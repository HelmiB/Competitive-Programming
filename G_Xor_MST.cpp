#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define int long long
const long double EPS = 1e-14;
const int maxn = 200500;
const int mod = 1e9 + 7;
int id[31 * maxn][2], nx[31 * maxn][2], a[maxn];
int cur = 1;

void insert(int X, int idx){
    int pos = 0;
    int bt = 30;
    while(bt >= 0){
        if(X & (1ll << bt)){
            if(id[pos][1] != idx){
                id[pos][1] = idx;
                nx[pos][1] = cur++;
            }
            pos = nx[pos][1];
        }
        else{
            if(id[pos][0] != idx){
                id[pos][0] = idx;
                nx[pos][0] = cur++;
            }
            pos = nx[pos][0];
        }
        bt--;
    }
}

long long search(int X, int idx){
    int pos = 0;    
    int bt = 30;
    long long sm = 0;
    while(bt >= 0){
        if(X & (1ll << bt)){
            if(id[pos][1] == idx) pos = nx[pos][1];
            else sm += (1ll << bt), pos = nx[pos][0];
        }else{
            if(id[pos][0] == idx) pos = nx[pos][0];
            else sm += (1ll << bt), pos = nx[pos][1];
        }
        bt--;
    }
    return sm;
}

long long solve(int l, int r, int bit, int idx = 1){
    if(l > r || bit == -1) return 0;
    int mid = l ;
    while(mid <= r){
        if(a[mid] & (1ll << bit)) break;
        mid++;
    }
    long long ans = 0;
    if(mid <= r && mid > l){
        cur = 1;
        for(int i = l ; i < mid ; ++i) insert(a[i], idx);
        long long best = 1e18;
        for(int i = mid; i <= r; ++i) best = min(best, search(a[i], idx));
        ans = best;
    }
    return ans + solve(l, mid - 1, bit - 1, 2 * idx + 1) + solve(mid, r, bit - 1, 2 * idx + 2);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    sort(a, a + n);
    cout << solve(0, n - 1, 29) << '\n';
    return 0;
}
