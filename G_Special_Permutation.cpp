#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<": "<<(x)<<'\n'
int t, n, i;
int main() {
	for(scanf("%d", &t); t--; ) {
		scanf("%d", &n);
		if (n<=3) {
			puts("-1");
		} else if (n==4) {
			puts("3 1 4 2");
		} else if (n==5) {
			puts("3 1 4 2 5");
		} else {
			for(i=2-(n&1); i<=n; i+=2) printf("%d ", i);
			printf("%d %d %d", i-5, i-3, i-7);
			for(i=i-9; i>=1; i-=2) printf(" %d", i);
			puts("");
		}
	}
}
