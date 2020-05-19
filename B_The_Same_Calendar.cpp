#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;

bool leap(int y){
    return (y % 400 == 0) || (y % 4 == 0 && (y % 100) != 0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int y;
    cin >> y;
    int x = y;
    int day = 0;
    while(1){
        day += 365 + leap(x);
        day %= 7;
        x++;
        if(!day && leap(x) == leap(y)) return cout << x << '\n', 0;
    }
    return 0;
}