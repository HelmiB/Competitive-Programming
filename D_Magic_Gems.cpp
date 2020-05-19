#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

struct matrix{
    int n, m;
    long long a[105][105];
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
                c.a[i][j]+=a.a[i][k]*b.a[k][j]%mod;
                c.a[i][j]%=mod;
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


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    if(n < m) return cout << 1 << '\n', 0;
    matrix a(m, m);
    a.a[m - 1][0] = a.a[0][0] = 1;
    for(int i = 1 ; i < m ; ++i) a.a[i - 1][i] = 1;
    //print(a);
    matrix f(m, 1);
    f.a[0][0] = 2;
    for(int i = 1 ; i < m ; ++i) f.a[i][0] = 1;
    f = (a ^ (n - m)) * f;
    cout << f.a[0][0] << '\n';
    return 0;
}