#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    stack < char > st;
    string s;
    cin >> s;
    int ans = 0;
    for(auto c : s){
        if(c == '(' || c == '{' || c == '[' || c == '<'){
            st.push(c);
            continue;
        }
        if(st.empty()) return cout << "Impossible\n", 0;
        auto u = st.top();
        st.pop();
        if(u == '(') u = ')';
        if(u == '{') u = '}';
        if(u == '[') u = ']';
        if(u == '<') u = '>'; 
        ans += (c != u);
    }
    if(!st.empty()) return cout << "Impossible\n", 0;
    cout << ans << '\n';
    return 0;
}
