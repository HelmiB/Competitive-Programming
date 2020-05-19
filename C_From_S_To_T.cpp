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
    int t;
    cin >> t;
    while(t--){
        string s, t, p;
        cin >> s >> t >> p;
        int cnt[30] = {0};
        for(auto c : p) cnt[c - 'a']++;
        bool can = true;    
        int j = 0;
        for(auto c : s){
            while(j < sz(t) && c != t[j]){
                if(!cnt[t[j] - 'a']) can = false;
                cnt[t[j] - 'a']--;
                ++j;
            }
            if(j == sz(t)){
                can = false;
                break;
            }
            ++j;
        }
        while(j < sz(t)){
            if(!cnt[t[j] - 'a']) can = false;
            cnt[t[j] - 'a']--;
            ++j;
        }
        cout << (can ? "YES":"NO") << '\n';
    }

    return 0;
}