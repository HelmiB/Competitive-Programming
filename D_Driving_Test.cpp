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
    int speed = 0;
    stack < int > sp, ov;
    int ans = 0;
    while(n--){
        int t;
        cin >> t;
        if(t == 1) cin >> speed;
        if(t == 2){
            while(sz(ov) && !ov.top()){
                ans++;
                ov.pop();
            }
        }
        if(t == 3){
            int x;
            cin >> x;
            sp.push(x);
        }
        if(t == 4) ov.push(1);
        if(t == 5) while(!sp.empty()) sp.pop();
        if(t == 6) ov.push(0);
        while(sz(sp) && sp.top() < speed){
            ans++;
            sp.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}