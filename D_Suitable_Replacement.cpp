#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int cnts[30], cntt[30];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s >> t;
    stack < int > st;
    for(int i = 0 ; i < sz(t) ; ++i) cntt[t[i] - 'a']++;
    for(int i = 0 ; i < sz(s); ++i){
        if(s[i] != '?') cnts[s[i] - 'a']++;
        else st.push(i);
    }
    while(!st.empty()){
        auto idx = st.top();
        st.pop();
        int ad = 1e9, id = -1;
        for(int i = 0 ; i < 26 ; ++i)
            if(cntt[i] && (cnts[i] / cntt[i] < ad)){
                ad = cnts[i] / cntt[i];
                id = i;
            }
        cnts[id]++;
        s[idx] = (char)(id + 'a');
    }
    cout << s << '\n';
    return 0;
}