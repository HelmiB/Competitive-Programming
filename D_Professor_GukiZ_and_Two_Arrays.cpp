#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[2020], b[2020];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    long long sa = 0, sb = 0;
    for(int i = 0 ; i < n ; ++i) cin >> a[i], sa += a[i];
    cin >> m;
    for(int i = 0 ; i < m ; ++i) cin >> b[i], sb += b[i];
    long long ans = abs(sa - sb);
    vector < pair < int, int > > res;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j){
            long long sm = abs(sa - sb - 2LL * a[i] + 2LL * b[j]);
            if(sm < ans){
                ans = sm;
                res.clear();
                res.push_back({i + 1, j + 1});
            }
        }
    vector < pair < long long , pair < int, int > > > as;
    for(int i = 0 ; i < n ; ++i)
        for(int j = i + 1 ; j < n ; ++j)
            as.push_back({a[i] + a[j], {i + 1, j + 1}});
    sort(all(as));
    for(int i = 0 ; i < m ; ++i)
        for(int j = i + 1 ; j < m ; ++ j){
            long long diff = sa - sb + 2LL * (b[i] + b[j]);
            diff /= 2;
            int idx = upper_bound(all(as), make_pair(diff, make_pair(-1, -1))) - as.begin();
            if(idx != sz(as)){
                long long sm = abs(sa - sb + 2LL * (b[i] + b[j]) - 2LL * as[idx].first);
                if(sm < ans){
                    ans = sm;
                    res.clear();
                    res.push_back({as[idx].second.first, i + 1});
                    res.push_back({as[idx].second.second, j + 1});
                }
            }
            if(idx){
                idx--;
                long long sm = abs(sa - sb + 2LL * (b[i] + b[j]) - 2LL * as[idx].first);
                if(sm < ans){
                    ans = sm;
                    res.clear();
                    res.push_back({as[idx].second.first, i + 1});
                    res.push_back({as[idx].second.second, j + 1});
                }
            }
        }
        cout << ans << '\n';
        cout << sz(res) << '\n';
        for(auto x : res) cout << x.first << ' ' << x.second << '\n';
        #include<ext/pb_ds/assoc_container.hpp>
        #include<ext/pb_ds/tree_policy.hpp>
        using namespace __gnu_pbds;
        template <typename T>
        using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
        
        /*  ordered_set<int>  s;
            s.insert(1); 
            s.insert(3);
            cout << s.order_of_key(2) << endl; // the number of elements in s less than 2
            cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based) */
        
    return 0;
}
