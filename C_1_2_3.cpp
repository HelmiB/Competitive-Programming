#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int A[5][5], B[5][5];

int res(int a, int b){
    if(a == b) return 0;
    if(a > b){
        if(a == 3 && b == 1) return 2;
        return 1;
    }
    if(a == 1 && b == 3) return 1;
    return 2;
}

void brute(int k, int a, int b){
    int ansa = 0, ansb = 0;
    if(res(a, b) == 1) ansa = 1;
    else if(res(a, b) == 2) ansb = 1;
    for(int i = 0 ; i < k ; ++i){
        int da = A[a][b];
        int db = B[a][b];
        if(res(da, db) == 1) ansa++;
        else if(res(da, db) == 2) ansb++;
        a = da;
        b = db;
    }
    cout << ansa << ' ' << ansb << '\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    set < pair < int, int > > in;
    int k, a, b;
    cin >> k >> a >> b;
    --k;
    in.insert({a, b});
    for(int i = 1 ; i <= 3 ; ++i)
        for(int j = 1 ; j <= 3 ; ++j)
            cin >> A[i][j];
    for(int i = 1 ; i <= 3 ; ++i)
        for(int j = 1 ; j <= 3 ; ++j)
            cin >> B[i][j];
    //brute(k, a, b);
    int da, db;
    int ansa = 0, ansb = 0;
    if(res(a, b) == 1) ansa = 1;
    else if(res(a, b) == 2) ansb = 1;
    vector < pair < int, int > > v;
    v.push_back({a, b});
    while(k > 0){
        da = A[a][b];
        db = B[a][b];
        if(in.find({da, db}) != in.end()) break;
        v.push_back({da, db});
        if(res(da, db) == 1) ansa++;
        else if(res(da, db) == 2) ansb++;
        in.insert({da, db});
        a = da;
        b = db;
        k--;
    }
    int sa = 0, sb = 0;
    if(res(da, db) == 1) sa++;
    else if(res(da, db) == 2) sb++;
    int i = sz(v) - 1;
    int len = 1;
    while(i > 0 && v[i] != make_pair(da, db)){
        if(res(v[i].first, v[i].second) == 1) sa++;
        else if(res(v[i].first, v[i].second) == 2) sb++;
        --i;
        len++;
    }
    int dv = k / len;
    ansa += sa * dv, ansb += sb * dv;
    k %= len;
    for(int i = sz(v) - len; k > 0; --k, ++i){
        if(res(v[i].first, v[i].second) == 1) ansa++;
        else if(res(v[i].first, v[i].second) == 2) ansb++;
    }
    cout << ansa << ' ' << ansb << '\n';
    return 0;
}