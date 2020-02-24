#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
map < pair < int, map < long long, int > >, pair < int, long long > > dp;
map < long long, int > a[1010];
int n;
long long t[1010];

map < long long, int > decomp(long long x){
    map < long long, int > res;
    //cout << x << " = ";
    for(long long i = 2 ; i * i <= x ; ++i)
        while(x % i == 0){
            res[i]++;
            x /= i;
        }
    if(x != 1) res[x]++;
    /*for(auto v : res) cout << v.first << ' ' << v.second << '\n';
    cout << "----------\n";*/
    return res;
}

pair < int, long long > solve(int i, map < long long, int > k){
    if(i == n) return {1e6 , 1e6};
    if(dp.find({i, k}) != dp.end()) return dp[{i, k}];
    pair < int , long long > &ret = dp[{i, k}];
    auto ret1 = solve(i + 1, k);
    map < long long, int > tmp;
    for(auto x : a[i])
        if(k.find(x.first) != k.end())
            if(k[x.first] > x.second) tmp[x.first] = k[x.first] - x.second;
    for(auto x : k)
        if(a[i].find(x.first) == a[i].end())
            tmp[x.first] = x.second;
    if(!sz(tmp)){
        if(ret1.first == 1 && ret1.second < t[i]) return ret1;
        return ret = {1, t[i]};
    }
    auto ret2 = solve(i + 1, tmp);
    ret2.second += t[i];
    ret2.first++;
    if(ret2.first == ret1.first){
        if(ret2.second < ret1.second) return ret = ret2;
        return ret = ret1;
    }
    if(ret2.first < ret1.first) return ret = ret2;
    return ret = ret1;
}

void print(int i, map < long long, int > k){
    if(i == n) assert(false);
    map < long long, int > tmp;
    for(auto x : a[i])
        if(k.find(x.first) != k.end())
            if(k[x.first] > x.second) tmp[x.first] = k[x.first] - x.second;
    for(auto x : k)
        if(a[i].find(x.first) == a[i].end())
            tmp[x.first] = x.second;
    if(!sz(tmp)){
        if(dp[{i, k}].second < t[i]) print(i + 1, k);
        else cout << i + 1 << '\n';
        return;
    }
    if(dp[{i, k}] == dp[{i + 1, k}]) print(i + 1, k);
    else{
        cout << i + 1 << ' ';
        print(i + 1, tmp);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long k;
    cin >> n >> k;
    for(int i = 0 ; i < n ; ++i){
        long long x;
        cin >> x;
        a[i] = decomp(x);
        t[i] = x;
    }
    int ans = solve(0, decomp(k)).first;
    if(ans > n) return cout << -1 << '\n', 0;
    else{
       cout << ans << '\n';
       print(0, decomp(k)); 
    }
    return 0;
}
