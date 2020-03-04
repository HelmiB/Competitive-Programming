#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
set < int > col[28];
int res[maxn];
int n;
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(int i = 0 ; i < n ; ++i) col[i].insert(0);
    al.insert(0);
    for(int i = 0 ; i < n ; ++i){
        set < int > tmp;
        for(int j = (int)(s[i] - 'a') + 1 ; j < 26 ; ++j)
            for(auto x : col[j])
                tmp.insert(x);
        int cur = 0;
        for(auto x : tmp)
            if(x == cur) cur++;
            else break;
        col[s[i] - 'a'].insert(cur);
        res[i] = cur;
    }
    set < int > al;
    for(int i = 0 ; i < 26 ; ++i)
        for(auto x : col[i])
            al.insert(x);
    cout << sz(al) << '\n';
    for(int i = 0 ; i < n ; ++i) cout << res[i] << ' ';
    cout << '\n';
    return 0;
}
