#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
bool ed[1010][1010];
pair < int, int > lv[50];

void add_edge(int i, int j){
    ed[i][j] = ed[j][i] = true;
}

int nxt;
void solve(int st, int d){
    if(st == -1) return;
    int cur = st;
    while(d--){
        add_edge(cur, nxt);
        cur = nxt++;
    }
    add_edge(1, cur);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k;
    cin >> k;
    add_edge(0, 3);
    add_edge(0, 4);
    pair < int, int > cur = {3, 4};
    lv[0] = {0, -1};
    lv[1] = cur;
    for(int i = 2 ; i <= 30 ; ++i){
        add_edge(cur.first, cur.first + 2);
        add_edge(cur.second, cur.first + 2);
        add_edge(cur.first, cur.second + 2);
        add_edge(cur.second, cur.second + 2);
        cur = {cur.first + 2, cur.second + 2};
        lv[i] = cur;
    }
    nxt = cur.second + 1;
    for(int i = 0 ; i < 32 ; ++i)
        if((1ll << i) & k){
            int d = 30 - i;
            solve(lv[i].first, 30 - i);
            solve(lv[i].second, 30 - i);
        }
    cout << 1000 << '\n';
    for(int i = 0 ; i < 1000; ++i){
        for(int j = 0 ; j < 1000; ++j)
            cout << (ed[i][j] ? "Y":"N");
        cout << '\n';
    }
    return 0;
}
