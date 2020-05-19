#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long long gcd(long long a, long long b, long long& x, long long& y) {
	if (!a) {
		x = 0, y = 1;
		return b;
	}
	long long xx, yy, g = gcd(b % a, a, xx, yy);
	x = yy - b / a * xx;
	y = xx;
	return g;
}
long long _ceil(long long a, long long b);
long long _floor(long long a, long long b) { return b < 0 ? _floor(-a, -b) : a < 0 ? -_ceil(-a, b) : a / b; }
long long _ceil(long long a, long long b) { return b < 0 ? _ceil(-a, -b) : a < 0 ? -_floor(-a, b) : (a + b - 1) / b; }


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long a1, b1, a2, b2, l, r;
    cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
    l = max(0ll, _ceil(l - b1, a1));
	r = _floor(r - b1, a1);
    long long A = a1, B = -a2, C = b2 - b1;
	long long x0, y0;
	long long g = gcd(A, B, x0, y0);
	if (C % g) {
		puts("0");
		return 0 ;
	}

	if (g < 0) {
		g = -g;
		x0 = -x0;
		y0 = -y0;
	}

	long long L = _ceil(r * g - x0 * C, B);
	long long R = _floor(l * g - x0 * C, B);
	R = min(R, _floor(y0 * C, A));
    cout << max(0LL, R - L + 1);
    return 0;
}