#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define D(x) cerr << #x << " = " << (x) << '\n'
using ll = long long;

template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x−axis in interva l [−pi , pi ]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes d is t ()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated ’a ’ radians ccw around the origin
	P rotate(double a) const {
	return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

using P = Point<ll>;

int solve() {
	int n;
	cin >> n;
	vector<P> p(n);
	vector<int> idxs(n);
	for(int i = 0; i < n; ++ i) {
		cin >> p[i].x >> p[i].y;
		idxs[i] = i;
	}
	if(n <= 4) return n;
	ll ans = 0;
	do {
		P dir = p[idxs[2]] - p[idxs[1]];
		ll curr_ans = 4;
		if(n == 5) {
			P dir1 = p[idxs[4]] - p[idxs[3]];
			if(dir.cross(dir1) == 0) curr_ans += 1;
		} else if(n == 6) {
			P dir1 = p[idxs[4]] - p[idxs[3]];
			if(dir.cross(dir1) == 0) curr_ans += 2;
		} else if(n == 7) {
			P dir1 = p[idxs[4]] - p[idxs[3]];
			if(dir.cross(dir1) == 0) {
				curr_ans += 2;
				dir1 = p[idxs[6]] - p[idxs[5]];
				if(dir.cross(dir1) == 0) curr_ans += 1;
			}
		}
		ans = max(ans, curr_ans);
	} while(next_permutation(all(idxs)));
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	for(int T = 1; T <= t; ++ T) {
		cout << "Case #" << T << ": " << solve() << '\n';
	}
}