#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e6;

struct matrix{
    int n, m;
    long long a[20][20];
    matrix(int _n, int _m){
        n=_n;
        m=_m;
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < m ; ++j)
                a[i][j] = 0;
    }
};
matrix operator*(const matrix &a,const matrix &b){
    assert(a.m == b.n);
    matrix c(a.n, b.m);
    for(int i = 0;i<a.n;i++){
        for(int j = 0; j< b.m ;j++){
            for(int k = 0;k < a.m ;k++){
                c.a[i][j]+=(a.a[i][k] % mod * b.a[k][j] % mod)%mod;
                c.a[i][j] %= mod;
            }
        }
    }
    return c;
}
matrix operator^(const matrix &a,long long b){
    assert(a.n == a.m);
    matrix res(a.n, a.n), temp = a;
    for(int i = 0 ; i < a.n ; ++i) res.a[i][i] = 1;
    while(b){
        if(b&1)res=res*temp;
        temp=temp*temp;
        b>>=1;
    }
    return res;
}
void print(matrix &m){
    for(int i = 0;i<m.n;i++){
        for(int j=0;j<m.m;j++)
            cout << m.a[i][j] << ' ';
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n, l, k;
    cin >> n >> k >> l;
    l %= mod; k %= mod;
    n /= 5;
    matrix a(2, 2), f0(2, 2);
    a.a[0][0] = k, a.a[0][1] = l; a.a[1][0] = 1;
    f0.a[0][0] = k; f0.a[1][0] = 1;
    a = (a ^ (n - 1)) * f0;
    string ans = to_string(a.a[0][0] );
    for(int l = sz(ans); l < 6 ; ++l) cout << 0;
    cout << a.a[0][0] << '\n';
    return 0;
}