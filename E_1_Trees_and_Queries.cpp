#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
const int maxn = 100500;
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
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
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};


typedef Point<ll> P;

ll polygonArea2(P a, P b, P c, P d) {
	ll res = d.cross(a);
    res += a.cross(b);
    res += b.cross(c);
    res += c.cross(d);
	return res;
}

bool segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
    return sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0;
}



bool check(P a, P b, P c, P d){
    return segInter(a, b, c, d) || segInter(a, d, b, c);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int tc = 1 ; tc <= t ; ++tc){
        int n;
        cin >> n;
        vector<P> a(n);
        for(int i = 0; i < n; ++ i) cin >> a[i].x >> a[i].y;
        ll ans = LLONG_MAX;
        for(int i1 = 0; i1 < n; ++ i1) {
            for(int i2 = 0; i2 < n; ++ i2) {
                if(i1 == i2) continue;
                for(int i3 = 0; i3 < n; ++ i3) {
                    if(i2 == i3 || i3 == i1) continue;
                    for(int i4 = 0; i4 < n; ++ i4) {
                        if(i4 == i1 || i4 == i2 || i4 == i3) continue;
                        if(!check(a[i1], a[i2], a[i3], a[i4])) ans = min(ans, abs(polygonArea2(a[i1], a[i2], a[i3], a[i4])));
                    }
                }
            }
        }
        cout << "Case #" << tc << ": ";
        cout << ans << '\n';
    }
    return 0;
}
