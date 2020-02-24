#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int n, m, k;
vector < pair < int, string > > ops;
void NO(){
    cout << "NO\n";
    exit(0);
}
void add(int m, int n, string c1, string c2, string c3){
    for(int j = 1 ; j < m ; ++j){
        if(n > 1){
            ops.push_back({n - 1, c1});
            ops.push_back({n - 1, c2});
        }   
        ops.push_back({1, c3});
	}
	if(n > 1) ops.push_back({n - 1, c1});
}

void YES(int idx, int acc){
    acc = min(k, acc);
    cout << "YES" << '\n';
	cout << idx + 1 << '\n';
    for(int i = 0 ; i < idx ; ++i){
        cout << ops[i].first << ' ' << ops[i].second << '\n';
        acc -= ops[i].first;
    }
    cout << acc << ' ' << ops[idx].second << '\n';
    exit(0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    if(k > 4 * n * m - 2 * (n + m)) NO();
    add(m, n, "D", "U", "R");
    add(n, m, "L", "R", "U");
    long long ad = 0;
    for(int i = 0 ; i < sz(ops); ++i){
        ad += ops[i].first;
        if(ad >= k) YES(i, ad);
    }
    assert(false);
    return 0;
}
