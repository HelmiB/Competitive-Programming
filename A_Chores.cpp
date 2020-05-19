#include "bits/stdc++.h"
using namespace std;
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
const int N = 1e6;
const int X = 2e6;

int n, p;
int spf[X+2];
int occ[X+2];

inline int _power(const LL &x, const LL &n){if(n==0)return 1;int y=_power(x, n>>1);y=y*y;return (n&1)?y*x:y;}

void contrib(int x, int add){
	while(x > 1){
		int pr = spf[x];
		occ[pr] += add;
		x /= pr;
	}
}

LD f(int x){
	memset(occ, 0, sizeof(occ));
	contrib(x, 1);
	
	for(int i=1; i<=n; ++i){
		contrib(i, 1);
	}
	for(int i=1; i<=p-1; ++i){
		contrib(i, -1);
	}
	for(int i=1; i<=n-(p-1); ++i){
		contrib(i, -1);
	}
	
	for(int i=1; i<=n+x; ++i){
		contrib(i, -1);
	}
	for(int i=1; i<=p; ++i){
		contrib(i, 1);
	}
	for(int i=1; i<=n+x-p; ++i){
		contrib(i, 1);
	}

	vector<int> pos, neg;
	for(int key=1; key<=X; ++key){
		int val = occ[key];
		if(val > 0){
			pos.emplace_back(_power(key, val));
		}
		if(val < 0){
			neg.emplace_back(_power(key, -val));
		}
	}

	LD tans = 1.0L;
	while(!empty(pos) || !empty(neg)){
		if(!empty(pos)){
			tans *= pos.back();
			pos.pop_back();
		}
		if(!empty(neg)){
			tans /= neg.back();
			neg.pop_back();
		}
	}

	return tans;
}

int main(){ FAST
	for(int i=1; i<=X; ++i){
		spf[i] = i;
	}
	for(int i=2; i<=X; ++i) if(spf[i] == i){
		for(int j=i+i; j<=X; j+=i){
			spf[j] = min(spf[j], i);
		}
	}

	cin >> n >> p;

	LD ans = f(1);
	LD curAns = f(1);
	for(int x=2; x<=n; ++x){
		curAns *= x;
		curAns /= x-1;

		curAns /= n+x;

		curAns *= n+x-p;

		ans = max(ans, curAns);
	}

	cout << fixed << setprecision(6) << ans << ln;
}