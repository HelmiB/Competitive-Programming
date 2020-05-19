#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int cnt[26][maxn];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    for(int i = sz(s) - 1 ; i >= 0 ; --i)
        for(int j = 0 ; j < 26 ; ++j)
            cnt[j][i] = cnt[j][i + 1] + (s[i] == (char)(j + 'a'));
    stack < char > st;
    for(int i = 0 ; i < sz(s) ; ++i){
        while(!st.empty()){
            int k = st.top() - 'a';
            bool flag = true;
            for(int j = 0 ; j < k ; ++j)
                if(cnt[j][i]){
                    flag = false;
                    break;
                }
            if(!flag) break;
            cout << st.top();
            st.pop();
        }
        int k = s[i] - 'a';
        bool flag = true;
        for(int j = 0 ; j < k ; ++j)
            if(cnt[j][i]){
                flag = false;
                break;
            }
        if(flag) cout << s[i];
        else st.push(s[i]);
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    cout << '\n';
    return 0;
}