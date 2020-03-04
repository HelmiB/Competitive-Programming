#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <assert.h>
using namespace std;
template<typename...T>void read(T&...x){((cin>>x),...);}template<typename...T>void write(T...x){((cout<<x),...);}
void __print(long long x){cerr<<x;}void __print(int x){cerr<<x;}
void __print(char x){cerr<<'\''<<x<<'\'';}void __print(const string &x){cerr<<'"'<<x<<'"';}
void __print(bool x){cerr<<(x?"true":"false");}void _print(){cerr<<"\n";}
template<typename T,typename U>void __print(const pair<T,U>&x){cerr<<'{';__print(x.first);cerr<<',';__print(x.second);cerr<<'}';}
template<typename T>void __print(const T&x){int f=0;cerr<<'{';for(auto&i:x)cerr<<(f++?",":""),__print(i);cerr<<"}";}
template<typename T,typename...U>void _print(T t,U...u){__print(t);if(sizeof...(u))cerr<<", ";_print(u...);}
#define dbg(x ...) cerr << "!?  " << # x << " = "; _print(x) 
#define FAST ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define LL long long
#define all(x) x.begin(),x.end()
#define loop(i,start,end) for(int i=start;i<=end;++i)
#define rloop(i,start,end) for(int i=start;i>=end;--i)
//#define int long long
//***********************************************************************************************************
const int N= 1000 +3;
const int INF= 1e9;
int n,m; char grid[N][N]; int nb[N][N]; int mn[N][N][12];

int get(int r, int c, int sz){
	int ans=INF;
	while(sz){
		int curPower = 31-__builtin_clz(sz);
		ans = min(ans,mn[r][c][curPower]);
		r+=(1<<curPower);
		sz-=(1<<curPower);
	}
	assert(ans != INF);
	return ans;
}

int32_t main(){ FAST 
	read(n,m);
	loop(i,1,n)
	loop(j,1,m) read(grid[i][j]);

	rloop(c,m,1) loop(r,1,n) nb[r][c] = (grid[r][c]==grid[r][c+1]) ? 1+nb[r][c+1] : 1;

	loop(lg,0,0)  loop(r,1,n) loop(c,1,m) mn[r][c][0] = nb[r][c];
	loop(lg,1,10) loop(r,1,n) loop(c,1,m){
		if(r + (1<<lg) - 1 > n) continue;
		mn[r][c][lg] = min(mn[r][c][lg-1] , mn[r+(1<<(lg-1))][c][lg-1]);
	}

	int best=-1;
	int lo=1,hi=min(n,m);
	while(lo <= hi){
		int mid = (lo+hi)>>1;
		bool found = false;

		loop(r,1,n) loop(c,1,m){
			int sz = min(mid,n-r+1);
			found |= (get(r,c,sz) >= sz);
		}

		if(found) best = mid, lo = mid+1;
		else hi = mid-1;
	}
	assert(best >= 1);
	write(best*best, "\n");
}