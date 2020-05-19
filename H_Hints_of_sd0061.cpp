#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
unsigned x, y, z;
unsigned a[100 * maxn];
unsigned rng61() {
	unsigned t;
	x = x ^ (x << 16);
	x = x ^ (x >> 5);
	x = x ^ (x << 1);
	t = x;
	x = y;
	y = z;
	z = (t ^ x) ^ y;
	return z;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector < unsigned > v;
    unsigned n, m, A, B, C;
    int tc = 1;
    while(cin >> n){
        cin >> m >> A >> B >> C;
        x = A, y = B , z = C;
        for(int i = 0 ; i < n ; ++i) a[i] = rng61();
        cout << "Case #" << tc << ": "; 
        vector < pair < int, int > > bs(m);
        vector < unsigned > ans(m, 0);
        int id = 0;
        for(auto &x : bs) cin >> x.first, x.second = id++;
        sort(all(bs));
        reverse(all(bs));
        map < int, unsigned > done;
        for(auto b : bs){
            if(done.find(b.first) != done.end()){
                ans[b.second] = done[b.first];
                continue;
            }
            nth_element(a, a + b.first, a + n);
            ans[b.second] = a[b.first];
            done[b.first] = a[b.first];
            n = b.first;
        }
        for(auto x : ans) cout << x << ' ';
        cout << '\n';
        tc++;
    }
    

    return 0;
}
