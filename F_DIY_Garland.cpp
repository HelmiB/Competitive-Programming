#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int deg[2 * maxn], p[2 * maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) deg[i] = 1;
    vector < int > v;
    for(int i = 0 ; i < n - 1 ; ++i){
        int x;
        cin >> x;
        x--;
        v.push_back(x);
        deg[x]++;
    }
    set < int > st;
    for(int i = 0 ; i < n ; ++i)
        if(deg[i] == 1)
            st.insert(i);
    int r = v[0];
    while(sz(v)){
        p[*st.begin()] = v.back();
        st.erase(*st.begin()); 
        deg[v.back()]--;
        if(deg[v.back()] == 1) st.insert(v.back());
        v.pop_back();
    }
    cout << r + 1 << '\n';
    for(int i = 0 ; i < n ; ++i)
        if(r != i)
            cout << i + 1 << ' ' << p[i] + 1 << '\n';    
    return 0;
}
