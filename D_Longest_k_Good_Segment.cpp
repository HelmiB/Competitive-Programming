#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int cnt[10 * maxn];
int a[5 * maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    int ans = 0, sm = 0;
    int bl = -1, br = -1;
    int l = 0;
    for(int r = 0 ; r < n ; ++r){
        cnt[a[r]]++;
        if(cnt[a[r]] == 1) sm++;
        while(sm > k){
            cnt[a[l]]--;
            if(!cnt[a[l]]) sm--;
            l++;
        }
        if(r - l + 1 > ans){
            ans = r - l + 1;
            bl = l + 1;
            br = r + 1;
        }
    }
    cout << bl << ' ' << br << '\n';
    return 0;
}
