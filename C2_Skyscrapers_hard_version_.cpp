#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 500500;
const int mod = 1e9 + 7;
int a[maxn], L[maxn], R[maxn], res[maxn];

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    stack < int > st;
    for(int i = 0 ; i < n ; ++i){
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        L[i] = (st.empty() ? (i + 1) * a[i]:(i - st.top()) * a[i] + L[st.top()]);
        st.push(i);
    }
    while(!st.empty()) st.pop();
    int ans = 0, idx = -1;
    for(int i = n - 1 ; i >= 0; --i){
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        R[i] = (st.empty() ? (n - i) * a[i]:(st.top() - i) * a[i] + R[st.top()]);
        if(L[i] + R[i] - a[i] > ans) ans = L[i] + R[i] - a[i], idx = i;
        st.push(i);
    }
    int i = idx - 1, x = a[idx];
    res[idx] = a[idx];
    while(i >= 0){
            x = min(x, a[i]);
            res[i] = x;
            --i;
    }
    i = idx + 1, x = a[idx];
    while(i < n){
        x = min(x, a[i]);
        res[i] = x;
        ++i;
    }
    for(int i = 0 ; i < n ; ++i) cout << res[i] << ' ';
    cout << '\n';
    return 0;
}
