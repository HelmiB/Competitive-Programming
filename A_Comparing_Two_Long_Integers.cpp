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
    string a, b;
    cin >> a >> b;
    if(sz(a) > sz(b)){
        reverse(all(b));
        while(sz(b) < sz(a)) b += "0";
        reverse(all(b));
    }else{
        reverse(all(a));
        while(sz(a) < sz(b)) a += "0";
        reverse(all(a));
    }
    for(int i = 0 ; i < sz(a) ; ++i)
        if(a[i] < b[i]) return cout << "<\n", 0;
        else if(a[i] > b[i]) return cout << ">\n", 0;
    cout << '=' << '\n';
    return 0;
}
