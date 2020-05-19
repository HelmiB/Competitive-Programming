#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


int sum(int a, int n, int r) {
	return n * (2 * a + (n - 1) * r) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	for(int T = 1; T <= tc; ++ T){
		int l, r;
		cin >> l >> r;
		if(l < r) {
			int diff = r - l, ans = 0, v = 0;
			int lo = 0, hi = 1e9;
			while(lo < hi) {
				int mid = (lo + hi + 1) / 2;
				if(sum(1, mid, 1) < diff) lo = mid;
				else hi = mid - 1;
			}
			r -= sum(1, lo, 1);
			ans = v = lo;
			v++;
			lo = 0, hi = 1e9;
			while(lo < hi) {
				int mid = (lo + hi + 1) / 2;
				if(sum(v, mid, 2) <= r) lo = mid;
				else hi = mid - 1;
			}
			ans += lo;
			r -= sum(v, lo, 2);
			lo = 0, hi = 1e9;
			while(lo < hi) {
				int mid = (lo + hi + 1) / 2;
				if(sum(v + 1, mid, 2) <= l) lo = mid;
				else hi = mid - 1;
			}
			ans += lo;
			l -= sum(v + 1, lo, 2);
			cout << "Case #" << T << ": " << ans << " " << l << " " << r << '\n';
		} else {
			int diff = l - r, ans = 0, v = 0;
			int lo = 0, hi = 1e9;
			while(lo < hi) {
				int mid = (lo + hi + 1) / 2;
				if(sum(1, mid, 1) <= diff) lo = mid;
				else hi = mid - 1;
			}
			l -= sum(1, lo, 1);
			ans = v = lo;
			v++;
			lo = 0, hi = 1e9;
			while(lo < hi) {
				int mid = (lo + hi + 1) / 2;
				if(sum(v, mid, 2) <= l) lo = mid;
				else hi = mid - 1;
			}
			ans += lo;
			l -= sum(v, lo, 2);
			lo = 0, hi = 1e9;
			while(lo < hi) {
				int mid = (lo + hi + 1) / 2;
				if(sum(v + 1, mid, 2) <= r) lo = mid;
				else hi = mid - 1;
			}
			ans += lo;
			r -= sum(v + 1, lo, 2);
			cout << "Case #" << T << ": " << ans << " " << l << " " << r << '\n';
		}
	}
}