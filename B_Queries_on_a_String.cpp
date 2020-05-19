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
    string s;
    cin >> s;
    reverse(all(s));
    int q;
    cin >> q;
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        --l; --r;
        l = sz(s) - l - 1, r = sz(s) - r - 1;
        swap(l, r);
        string tmp = "";
        for(int i = l ; i <= r ; ++i) tmp += s[i];
        k %= sz(tmp);
        int i = k, idx = l;
        while(idx <= r){
            i %= sz(tmp);
            s[idx++] = tmp[i++];
        }
    }
    reverse(all(s));
    cout << s << '\n';
    return 0;
}
