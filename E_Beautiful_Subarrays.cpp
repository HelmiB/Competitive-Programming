#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1000500;
const int mod = 1e9 + 7;
int trie[2][30 * maxn], cnt[30 * maxn];
int nx = 1, n, k;

void insert(int x){
    int cur = 0;
    for(int j = 29 ; j >= 0 ; --j)
        if(x & (1 << j)){
            if(trie[1][cur] == -1) trie[1][cur] = nx++;
            cur = trie[1][cur];
            cnt[cur]++;
        }else{
            if(trie[0][cur] == -1) trie[0][cur] = nx++;
            cur = trie[0][cur];
            cnt[cur]++;
        }
}

long long get(int x){
    int cur = 0;
    long long ans = 0;
    for(int j = 29 ; j >= 0 ; --j)
        if(k & (1 << j)){
            if(x & (1 << j)){
                if(trie[0][cur] == -1) return ans;
                cur = trie[0][cur];
            }else{
                if(trie[1][cur] == -1) return ans;
                cur = trie[1][cur];
            }
        }else{
            if(x & (1 << j)){
                if(~trie[0][cur]) ans += cnt[trie[0][cur]];
                if(trie[1][cur] == -1) return ans;
                cur = trie[1][cur];
            }else{
                if(~trie[1][cur]) ans += cnt[trie[1][cur]];
                if(trie[0][cur] == -1) return ans;
                cur = trie[0][cur];
            }
        }
    return ans + cnt[cur];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(trie, -1, sizeof trie);
    cin >> n >> k;
    long long ans = 0, xr = 0;
    insert(0);
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        xr ^= x;
        insert(xr);
        ans += get(xr);
    }
    cout << ans << '\n';
    return 0;
}