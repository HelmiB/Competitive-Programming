#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const int N = 1e5 + 5;

#define fi first
#define se second

#define lc(o) (o << 1)
#define rc(o) (o << 1 | 1)

P sgt[N * 4];

inline P upd(const P &x, const P &y) {
	return {min(x.fi, y.fi), max(x.se, y.se)};
}

P qry(int o, int ql, int qr, int l, int r) {
	if (l >= ql && r <= qr)
		return sgt[o];
	int m = (l + r) >> 1;
	if (ql >= m + 1)
		return qry(rc(o), ql, qr, m + 1, r);
	else if (qr <= m)
		return qry(lc(o), ql, qr, l, m);
	else
		return upd(qry(lc(o), ql, qr, l, m), qry(rc(o), ql, qr, m + 1, r));
}

ll a[N], b[N]; P nxt[N][2][25];

int n, LB, UB;

void build(int o, int l, int r) {
	if (l == r) {
		sgt[o] = {b[l], b[l]};
		return;
	}
	int m = (l + r) >> 1;
	build(lc(o), l, m);
	build(rc(o), m + 1, r);
	sgt[o] = upd(sgt[lc(o)], sgt[rc(o)]);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> LB >> UB;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[n + 1] = 0;
	for (int i = 1; i <= n + 1; i++)
		b[i] = b[i - 1] + a[i];
	build(1, 1, n);
	for (int i = 1, l, r; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			ll val = (j == 0 ? LB : UB);
			l = i + 1, r = n + 1;
			while (l < r) {
				int m = (l + r) >> 1;
				P p = qry(1, i + 1, m, 1, n); p = {p.fi - b[i] + val, p.se - b[i] + val};
				if (p.fi <= LB || p.se >= UB)
					r = m;
				else
					l = m + 1;
			}
			if (l <= n) {
				P p = qry(1, l, r, 1, n); p = {p.fi - b[i] + val, p.se - b[i] + val};
				if (p.fi <= LB)
					nxt[i][j][0] = {l, 0};
				else
					nxt[i][j][0] = {l, 1};
			}
		}
	}
	for (int k = 1; k <= 20; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 2; j++) {
				int x = nxt[i][j][k - 1].fi, y = nxt[i][j][k - 1].se;
				nxt[i][j][k] = nxt[x][y][k - 1];
			}
		}
	}
	int _; cin >> _;
	while (_--) {
		int L, R, X, l, r;
		cin >> L >> R >> X; l = L, r = R + 1;
		while (l < r) {
			int m = (l + r) >> 1;
			P p = qry(1, L, m, 1, n); p = {p.fi - b[L - 1] + X, p.se - b[L - 1] + X};
			if (p.fi <= LB || p.se >= UB)
				r = m;
			else
				l = m + 1;
		}
		if (l > R)
			cout << X + b[R] - b[L - 1] << endl;
		else {
			P cur_p = qry(1, L, l, 1, n); cur_p = {cur_p.fi - b[L - 1] + X, cur_p.se - b[L - 1] + X};
			int x = l, y = (cur_p.fi <= LB ? 0 : 1);
			for (int k = 20; k >= 0; k--) {
				if (nxt[x][y][k].fi != 0 && nxt[x][y][k].fi <= R) {
					P z = nxt[x][y][k];
					x = z.fi, y = z.se;
				}
			}
//			cout << "x: " << x << " y: " << y << endl;
			X = (y == 0 ? LB : UB);
			cout << X + b[R] - b[x] << endl;
		}
	}
	return 0;
}