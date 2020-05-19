#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

void yes(){
    cout << "yes\n";
    exit(0);
}

void no(){
    cout << "no\n";
    exit(0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b;
    cin >> a >> b;
    if(a == b) yes();
    if(sz(b) > sz(a) || sz(a) < 8) no();
    if(sz(a) > sz(b) + 1) no();
    if(sz(a) == sz(b)){
        int cnt = 0;
        for(int i = 0 ; i < sz(a) ; ++i) cnt += a[i] != b[i];
        if(cnt > 1) no();
        yes();
    }else{
        int i = 0, j = 0;
        int cnt = 0;
        while(i < sz(a) && j < sz(b)){
            if(a[i] != b[j]) ++i, cnt++;
            else ++i, ++j;
        }
        if(cnt > 1) no();
        yes();
    }
    return 0;
}