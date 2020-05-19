#include<bits/stdc++.h>			
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int iter = 1;
double dp[51][51][51][51];
int vis[51][51][51][51];
class BlindBoxSets {
public:
    int n, s;
    double solve(int a, int b, int c, int d){
        if((a + b + c + d) == 0) return 0;
        double &ret = dp[a][b][c][d];
        if(vis[a][b][c][d] == iter) return ret;
        vis[a][b][c][d] = iter;
        ret = 0;
        int n0 = n - a - b - c - d;
        ret = 0;
        if(a) ret += (a * 1.0) / n * solve(a - 1, b, c, d);
        if(b) ret += (b * 1.0) / n * solve(a + 1, b - 1, c, d);
        if(c) ret += (c * 1.0) / n * solve(a , b + 1, c - 1, d);
        if(d) ret += (d * 1.0) / n * solve(a , b, c + 1, d - 1);
        return ret = (n * 1.0) / (n - n0) * (1 + ret);
    }
	double expectedPurchases(int numSets, int numItems){
        s = numSets;
        n = numItems;
        iter++;
        int a = 0, b = 0, c = 0, d = 0;
        if(s == 1) a = n;
        if(s == 2) b = n;
        if(s == 3) c = n;
        if(s == 4) d = n;
        return solve(a, b, c, d);
	}
};
