#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < pair < string , int > > v;

inline bool cmp(const pair < string , int > &a, const pair < string , int > &b){
    string x = a.first + b.first;
    string y = b.first + a.first;
    if(y == x) return a.second < b.second;
    return x < y;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        string s;
        cin >> s;
        v.push_back({s, i});
    }
    sort(all(v), cmp);
    for(int i = 0 ; i < n ; ++i) cout << v[i].first;
    cout << '\n';
    return 0;
}