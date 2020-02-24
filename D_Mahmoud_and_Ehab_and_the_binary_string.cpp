#include<bits/stdc++.h>
using namespace std;
const int maxn = 100500;
const int mod = 1e9 + 7;
string org = "10";

int ask(string s){
    /*int cnt = 0;
    for(int i = 0 ; i < (int)s.length() ; ++i)
        cnt += (s[i] != org[i]);
    return cnt;*/
    cout << "? " << s << '\n';
    cout << flush;
    int res;
    cin >> res;
    return res;
}

char flip(char c){
    if(c == '0') return '1';
    return '0';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    //n = (int)org.size();
    cin >> n;
    string s = "";
    for(int i = 0 ; i < n ; ++i) s += "0";
    int r = ask(s);
    s[0] = '1';
    int r1 = ask(s);
    int one = -1, zer = -1;
    if(r < r1) zer = 0, s[0] = '0';
    else{
        one = 0;
        for(int i = 1 ; i < n ; ++i) s[i] = '1';
        r = ask(s);
    }
    int lo = 0, hi = n - 1;
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        string tm = s;
        for(int i = mid ; i <= hi ; ++i) tm[i] = flip(s[i]);
        int res = ask(tm);
        if(res == r + (hi - mid + 1)) hi = mid - 1;
        else lo = mid + 1;
    }
    if(~zer) one = lo - 1;
    else zer = lo - 1;
    cout << "! " << zer + 1 << ' ' << one + 1 << '\n';
    cout << flush;
    return 0;
}
