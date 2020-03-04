#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long long la, lb, ra, rb, ta, tb;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    int lo = -1, hi = 1e9 + 5;
    long long g = __gcd(tb, ta);
	long long ans = 0;
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			long long stA = (la % g) + i * g;
			long long enA = stA + ra - la + 1;
			long long stB = (lb % g) + j * g;
			long long enB = stB + rb - lb + 1;
			ans = max(ans, min(enA, enB) - max(stA, stB));
		}
	}
	cout << ans << '\n';
    return 0;
}
