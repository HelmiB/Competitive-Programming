#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1000500;
const int mod = 1e9 + 7;
bool in[maxn];
int occ[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a;
    cin >> n >> a;
    memset(in, true, sizeof in);
    set < pair < int, int > > st;
    for(int i = 1 ; i <= 1e6 ; ++i) 
        if(i != a)
            st.insert({occ[i], i});
    for(int i = 0 ; i < n ; ++i){
        int x;
        cin >> x;
        if(x == a){
            occ[a]++;
            while(sz(st) && st.begin()->first < occ[a]){
                auto u = *st.begin();
                st.erase(u);
                in[u.second] = false;
            }
        }else if(in[x]){
            st.erase({occ[x], x});
            occ[x]++;
            st.insert({occ[x], x});
        }
    }
    cout << (sz(st) ? st.begin()->second:-1) << '\n';
    return 0;
}