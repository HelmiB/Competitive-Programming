#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long

/*  ordered_set<int>  s;
    s.insert(1); 
    s.insert(3);
    cout << s.order_of_key(2) << endl; // the number of elements in s less than 2
    cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based) */

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    ordered_set < pair < int, int > > s;
    s.insert({0, 0});
    long long sm = 0;
    for(int i = 1 ; i <= n ; ++i){
        int x;
        cin >> x;
        sm += x;
        ans += s.order_of_key({sm - k * i, i});
        s.insert({sm - i * k, i});
    }
    cout << ans << '\n';
    return 0;
}