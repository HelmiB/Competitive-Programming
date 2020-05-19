#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
long long k;

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
            for(int p = 0;p < a.m ;p++){
                if(a.a[i][p] && b.a[p][j] > k / a.a[i][p]){
                    c.a[i][j] = k;
                    break;
                }
                if(c.a[i][j] >= k - a.a[i][p]*b.a[p][j]){
                    c.a[i][j] = k;
                    break;
                }
                c.a[i][j] += a.a[i][p]*b.a[p][j];
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
    int n;
    cin >> n >> k;
    vector < long long > v(n);
    for(auto &x : v) cin >> x;
    reverse(all(v));
    while(!v.back()) v.pop_back();
    reverse(all(v));
    n = sz(v);
    long long a[n];
    for(int i = 0 ; i < n ; ++i) a[i] = v[i];
    if(n >= 20){
        int it = 0;
        bool flag = false;
        if(*max_element(a, a + n) >= k) flag = true;
        while(!flag){
            ++it;
            for(int i = 1 ; i < n && !flag; ++i){
                a[i] += a[i - 1];
                if(a[i] >= k) flag = true;
            }
        }
        cout << it << '\n';
        return 0;
    }
    matrix m(n, n);
    matrix am(1, n);
    for(int i = 0 ; i < n ; ++i) am.a[0][i] = a[i];
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j <= i ; ++j)
            m.a[j][i] = 1;
    long long lo = 0, hi = 1e18;
    while(lo <= hi){
        long long mid = (lo + hi) >> 1;
        matrix res = am * (m ^ mid);
        bool flag = false;
        for(int i = 0 ; i < n && !flag; ++i)
            if(res.a[0][i] >= k)
                flag = true;
        if(flag) hi = mid - 1;
        else lo = mid + 1;
    }
    cout << hi + 1 << '\n';
    return 0;
}