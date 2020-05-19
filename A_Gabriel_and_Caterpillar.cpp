#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 2000500;
const int mod = 1e9 + 7;
int trie[maxn][26], cnt[maxn];
set < int > g[maxn];
int nxt, k;
set < pair < int, int > > in;

void insert(string &s, int i){
    int cur = 0;
    g[cur].insert(i);
    int pos = 0;
    for(auto c : s){
        int idx = c - 'A';
        if(trie[cur][idx] == -1) trie[cur][idx] = nxt++;
        cur = trie[cur][idx];
        cnt[cur] = ++pos;
        if(sz(g[cur]) >= k) in.erase({cnt[cur], cur});
        g[cur].insert(i);
        if(sz(g[cur]) >= k) in.insert({cnt[cur], cur});
    }
}

void rem(string s, int i){
    int cur = 0;
    g[cur].erase(i);
    for(auto c : s){
        int idx = c - 'A';
        cur = trie[cur][idx];
        if(sz(g[cur]) >= k) in.erase({cnt[cur], cur});
        g[cur].erase(i);
        if(sz(g[cur]) >= k) in.insert({cnt[cur], cur});
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(int tc = 1 ; tc <= T ; ++tc){
        int n;
        cin >> n >> k;
        nxt = 1;
        vector < string > vs(n);
        int len = 0;
        for(auto &s : vs){
            cin >> s;
            len += sz(s);
        }
        for(int i = 0 ; i <= len ; ++i){
            g[i].clear();
            for(int j = 0 ; j < 26 ; ++j) trie[i][j] = -1;
        }
        int i = 0;
        in.clear();
        for(auto s : vs) insert(s, i++);
        in.insert({0, 0});
        int ans = 0;
        for(int i = 1 ; i <= n / k ; ++i){
            auto u = *in.rbegin();
            ans += u.first;
            for(int j = 0 ; j < k ; ++j) rem(vs[*g[u.second].begin()], *g[u.second].begin());
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }
    return 0;
}