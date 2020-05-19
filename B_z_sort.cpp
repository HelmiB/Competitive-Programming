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
    int n;
    cin >> n;    
    vector < int > v(n);
    deque < int > dq;
    for(auto &x : v) cin >> x;
    sort(all(v));
    for(auto x : v) dq.push_back(x);
    bool turn = true;
    while(!dq.empty()){
        if(turn){
            cout << dq.front() << ' ';
            dq.pop_front();
        }else{
            cout << dq.back() << ' ';
            dq.pop_back();
        }
        turn = 1 - turn;
    }
    return 0;
}