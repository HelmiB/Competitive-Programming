#include "bits/stdc++.h"
using namespace std;
void __dump(int x){cerr << x;}
void __dump(long long x){cerr << x;}
void __dump(long double x){cerr << fixed << setprecision(3) << x;}
void __dump(char x){cerr << '\'' << x << '\'';}
void __dump(const string &x){cerr << '"' << x << '"';}
void __dump(const char *x){cerr << '"' << x << '"';}
void __dump(bool x){cerr << (x ? "true" : "false");}
void _dump(){cerr << "\n";}
template <typename T, typename U> void __dump(const pair<T, U> &x){cerr << '{'; __dump(x.first); cerr << ','; __dump(x.second); cerr << '}';}
template <typename T, typename U, typename V> void __dump(const tuple<T, U, V> &x){cerr << '{'; __dump(get<0>(x)); cerr << ',';  __dump(get<1>(x)); cerr << ',';  __dump(get<2>(x)); cerr << '}';}
template <typename T> void __dump(const T& x){int f=0; cerr << '{'; for(auto&i:x) cerr << (f++ ? "," : ""), __dump(i); cerr << "}";}
template <typename T, typename ... U> void _dump(T t, U ... u){__dump(t); if(sizeof...(u)) cerr << ", "; _dump(u...);}
#ifdef ilyes
	#define dump(x ...) cerr  <<  "|dumping| "  <<  # x  <<  "  =  ", _dump(x) 
#else
	#define dump(...) 1998
#endif
//#define int long long
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define size(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ln '\n'
#define __ ' '
#define LL long long
#define LD long double
#define pii pair<int,int>
const int INF = 1e9;
const int N = 1e5;

int n, m, node;
set<int> adj[N+2], revadj[N+2];
set<int> good, bad;

int main(){ FAST
	cin >> n >> m >> node; ++node;
	for(int i=1; i<=m; ++i){
		int u, v; cin >> u >> v; ++u, ++v;
		if(u == node) continue;
		adj[u].insert(v);
		revadj[v].insert(u);
	}

	for(int u=1; u<=n; ++u){
		if(adj[u].count(node)) good.insert(u);
	}

	set<pii> ss;
	for(int u=1; u<=n; ++u){
		ss.insert({size(adj[u]), u});
	}

	while(!empty(ss)){
		int deg, u;
		tie(deg, u) = *begin(ss);
		ss.erase(begin(ss));

		for(int v: revadj[u]){
			ss.erase({size(adj[v]), v});
			adj[v].erase(u);
			ss.insert({size(adj[v]), v});
			if(good.count(u)) bad.insert(v);
		}
		revadj[u].clear();
	}

	set<int> result;
	for(int u=1; u<=n; ++u){
		if(good.count(u) && !bad.count(u)) result.insert(u);
	}

	cout << size(result) << ln;
	for(int u: result) cout << u-1 << ln;

}