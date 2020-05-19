#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

struct ChineseRemainderTheorem{
    int inv(int a, int m){ 
        int m0 = m, t, q; 
        int x0 = 0, x1 = 1; 
        if (m == 1)  return 0; 
        while (a > 1) { 
            q = a / m; 
            t = m; 
            m = a % m, a = t; 
            t = x0; 
            x0 = x1 - q * x0; 
            x1 = t; 
        } 
        if (x1 < 0) x1 += m0; 
        return x1; 
    } 
    
    int solve(vector< int > num, vector < int > rem){
        assert(sz(num) == sz(rem));
        int prod = 1; 
        for (int i = 0; i < sz(num); i++) prod *= num[i]; 
        int result = 0; 
        for (int i = 0; i < sz(num); i++) { 
            int pp = prod / num[i]; 
            result += rem[i] * inv(pp, num[i]) * pp; 
        } 
        return result % prod; 
    } 
}crt;




string ask(string s){
    cout << "? " << s << '\n';
    cout << flush;
    string rep;
    cin >> rep;
    return rep;
}

void answer(string ans){
    cout << "! " << ans << '\n';
    cout << flush;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string t;
    cin >> t;
    string r[3];
    string q = "";
    for(int i = 0 ; i < sz(t) ; ++i) q += (char)(i % 26 + 'a');
    r[0] = ask(q);
    q = "";
    for(int i = 0 ; i < sz(t) ; ++i) q += (char)(i % 25 + 'a');
    r[1] = ask(q);
    q = "";
    for(int i = 0 ; i < sz(t) ; ++i) q += (char)(i % 23 + 'a');
    r[2] = ask(q);
    string ans = t;
    vector < int > num = {26, 25, 23};
    for(int i = 0 ; i < sz(t) ; ++i){
        vector < int > rem;
        for(int j = 0 ; j < 3 ; ++j) rem.push_back((r[j][i] - 'a') % num[j]);
        ans[crt.solve(num, rem)] = t[i];
    }
    answer(ans);
    return 0;
}