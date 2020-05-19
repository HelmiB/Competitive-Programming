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
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector < int > a(n);
        for(auto &x : a) cin >> x;
        ordered_set < pair < int, int > > mini, maxi;
        map < int , int > cnt;
        for(int i = 0 ; i < n / 2 ; ++i){
            cnt[a[i] + a[n - i - 1]]++;
            mini.insert({min(a[i], a[n - i - 1]), i});
            maxi.insert({max(a[i], a[n - i - 1]), i});
        }
        int ans = 1e9;
        for(int x = 2 ; x <= 2 * k ; ++x){
            int f = maxi.order_of_key({x - k, -1});
            int s = sz(mini) - mini.order_of_key({x, -1});
            int sm = 2 * (s + f) + n / 2 - s - f - cnt[x];
            ans = min(ans, sm);
        }
        cout << ans << '\n';
    }

    return 0;
}