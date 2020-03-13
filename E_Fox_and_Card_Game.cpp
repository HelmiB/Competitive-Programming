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
    int sm1 = 0, sm2 = 0;
    vector < int > mid;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        int k;
        cin >> k;
        for(int j = 0 ; j < k ; ++j){
            int x;
            cin >> x;
            if(k % 2 && j == (k - 1) / 2) mid.push_back(x);
            else if(j < k / 2) sm1 += x;
            else sm2 += x;
        } 
    }
    sort(all(mid));
    reverse(all(mid));
    for(int i = 0 ; i < sz(mid) ; ++i)
        if(i & 1) sm2 += mid[i];
        else sm1 += mid[i];
    cout << sm1 << ' ' << sm2 << '\n';
    return 0;
}
