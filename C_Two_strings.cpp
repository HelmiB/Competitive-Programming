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
    string s, t;
    cin >> s >> t;
    int idx = sz(s) - 1;
    priority_queue < pair < int, int > > pq;
    int ans = 1e9, l = -1, r = -1;
    for(int i = sz(t) - 1; i >= 0 ; --i){
        while(idx >= 0 && s[idx] != t[i]) idx--;
        if(idx < 0) break;
        pq.push({-i, idx});
        ans = i; l = -1; r = i;
        idx--;
    }
    idx = 0;
    pq.push({-sz(t), sz(s)});
    for(int i = 0 ; i < sz(t) ; ++i){
        while(idx < sz(s) && s[idx] != t[i]) idx++;
        if(idx == sz(s)) break;
        while(!pq.empty() && (pq.top().second <= idx || -pq.top().first <= i)) pq.pop();
        if(ans > -pq.top().first - i - 1){
            ans = -pq.top().first - i - 1;
            l = i;
            r = -pq.top().first;
        }
        idx++;
    }
    if(ans == 1e9) return cout << '-' << '\n', 0;
    for(int i = 0 ; i <= l ; ++i) cout << t[i];
    for(int i = r ; i < sz(t) ; ++i) cout << t[i];
    cout << '\n';
    return 0;
}