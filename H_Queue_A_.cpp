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
    map < int, int > cnt;
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        int ad = 0;
        cin >> ad;
        ad *= -1;
        int x;
        cin >> x;
        cnt[-1] += x;
        ad += x;
        cin >> x;
        ad += 5 * x;
        cnt[-5] += x;
        cin >> x;
        ad += 10 * x;
        cnt[-10] += x;
        cin >> x;
        ad += 20 * x;
        cnt[-20] += x;
        cin >> x;
        ad += 50 * x;
        cnt[-50] += x;
        for(auto &u : cnt){
            if(!ad) break;
            while(u.second && -u.first <= ad){
                ad += u.first;
                u.second--;
            }
        }
        if(ad) return cout << "no" << '\n', 0;
    }
    cout << "yes\n";
    return 0;
}