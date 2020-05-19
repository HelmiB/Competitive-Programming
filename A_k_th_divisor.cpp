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
    long long n, k;
    cin >> n >> k;
    stack < long long > st;
    for(long long i = 1 ; i * i <= n ; ++i)
        if(n % i == 0){
            k--;
            if(!k) return cout << i << '\n', 0;
            if(i != n / i) st.push(n / i); 
        }
    if(k > sz(st)) return cout << -1 << '\n', 0;
    while(k > 1) st.pop(), k--;
    cout << st.top() << '\n';
    return 0;
}