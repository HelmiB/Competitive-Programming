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
        int n;
        set < int > in;
        cin >> n;
        for(int i = 0 ; i < n ; ++i){
            int x;
            cin >> x;
            in.insert(x);
        }
        cout << sz(in) << '\n';
    }

    return 0;
}
