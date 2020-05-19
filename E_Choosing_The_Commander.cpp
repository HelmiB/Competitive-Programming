#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int trie[30 * maxn][2], cnt[30 * maxn];
int nxt = 1;

void insert(int x){
    int cur = 0;
    for(int j = 29 ; j >= 0; --j){
        if((1 << j) & x){
            if(trie[cur][1] == -1) trie[cur][1] = nxt++;
            cur = trie[cur][1];
        }else{
            if(trie[cur][0] == -1) trie[cur][0] = nxt++;
            cur = trie[cur][0];
        }
        cnt[cur]++;
    }
}

void remove(int x){
    int cur = 0;
    for(int j = 29 ; j >= 0; --j){
        if((1 << j) & x) cur = trie[cur][1];
        else cur = trie[cur][0];
        cnt[cur]--;
    }
}

int get(int p, int l){
    int cur = 0, ans = 0;
    for(int j = 29 ; j >= 0 && ~cur ; --j)
        if((1 << j) & p){
            if((1 << j) & l){
                if(~trie[cur][1]) ans += cnt[trie[cur][1]];
                cur = trie[cur][0];
            }else cur = trie[cur][1];
        }else{
            if((1 << j) & l){
                if(~trie[cur][0]) ans += cnt[trie[cur][0]];
                cur = trie[cur][1];
            }else cur = trie[cur][0];
        }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(trie, -1, sizeof trie);
    int q;
    cin >> q;
    while(q--){
        int t, p;
        cin >> t >> p;
        if(t == 1) insert(p);
        if(t == 2) remove(p);
        if(t == 3){
            int l;
            cin >> l;
            cout << get(p, l) << '\n';
        }
    }
    return 0;
}