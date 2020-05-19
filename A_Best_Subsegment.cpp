#include<bits/stdc++.h>
using namespace std;
#define int long long
int m = (1ll << 40);


int f(int x){
    return (x+(x/(1 << 20))+12345) & (m - 1init);
}

pair < int, int > floyd(int x0){
    int tortoise = f(x0); 
    int hare = f(f(x0));
    while(tortoise != hare){
        tortoise = f(tortoise);
        hare = f(f(hare));
    }
    int mu = 0;
    tortoise = x0;
    while(tortoise != hare){
        tortoise = f(tortoise);
        hare = f(hare);
        mu++;
    }
    int lam = 1;
    hare = f(tortoise);
    while(tortoise != hare){
        hare = f(hare);
        lam++;
    }
    return {lam, mu};
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x0 = 1611516670;
    auto ans = floyd(x0);
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}