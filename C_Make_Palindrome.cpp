#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int cnt[30];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    for(auto c : s) cnt[c - 'a']++;
    vector < int > od;
    for(int i = 0 ; i < 26 ; ++i)
        if(cnt[i] % 2) od.push_back(i);
    int l = 0, r = sz(od) - 1;
    while(l < r){
        cnt[od[l]]++;
        cnt[od[r]]--;
        l++; r--;
    }
    deque < char > d;
    if(l == r ) d.push_back((char)('a' + od[l]));
    for(int i = 25 ; i >= 0 ; --i)
        for(int j = 0 ; j < cnt[i] / 2 ; ++j){
            d.push_back((char)(i + 'a'));
            d.push_front((char)(i + 'a'));
        }
    while(!d.empty()){
        cout << d.front();
        d.pop_front();
    }
    return 0;
}
