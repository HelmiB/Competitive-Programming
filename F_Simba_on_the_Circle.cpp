#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int id[2050];
int a[maxn], b[maxn];
int dp[2][maxn], d[2010][2010], od[2010][2010];
map < int, int > cnt;
int cur, n;
int ad = 0;

int solve(bool idx, int i){
    int &ret = dp[idx][i];
    if(~ret) return ret;
    ret = 1e9;
    if(!idx){
        if(cnt[a[i]] == 1) return ret = solve(1, i);
        int l = i - 1;
        l = (l + n) % n;
        while(a[l] != a[i]){
            l--;
            l = (l + n) % n;
        }
        ret = solve(1, l) + od[l][i];
        l = i + 1;
        l %= n;
        while(a[l] != a[i]){
            l++;
            l %= n;
        }
        ret = min(ret, solve(1, l) + od[i][l]);
        return ret;
    }else{
        if(id[i] == cur - 1) return 0;
        for(int j = 0 ; j < n ; ++j)
            if(id[j] == id[i] + 1)
                ret = min(ret, solve(0, j) + d[i][j]);
        return ret;
    }
}

void track(bool idx, int i){
    assert(~i);
    if(!idx){
        if(cnt[a[i]] == 1) return track(1, i);
        int aa = 1e9, bb = 1e9;
        int l = i - 1;
        l = (l + n) % n;
        while(a[l] != a[i]){
            l--;
            l = (l + n) % n;
        }
        aa = solve(1, l) + od[l][i];
        int tmp = l;
        l = i + 1;
        l %= n;
        while(a[l] != a[i]){
            l++;
            l %= n;
        }
        bb = solve(1, l) + od[i][l];
        if(aa <= bb){
            int j = i;
            int sm = 0;
            while(j != tmp){
                j++;
                if(j == n) j = 0;
                sm++;
                if(a[j] == a[i]){
                    cout << "+" << sm << '\n';
                    sm = 0;
                }
            }
            track(1, tmp);
        }else{
            int j = i;
            int sm = 0;
            while(j != l){
                j--;
                if(j < 0) j = n - 1;
                sm++;
                if(a[j] == a[i]){
                    cout << "-" << sm << '\n';
                    sm = 0;
                }
            }
            track(1, l);
        }
        ad++;
    }else{
        if(id[i] == cur - 1) return ;
        int best = 1e9, idx = -1;
        for(int j = 0 ; j < n ; ++j)
            if(id[j] == id[i] + 1){
                int sm = solve(0, j) + d[i][j];
                if(sm < best) best = sm, idx = j;
            }
        if(i < idx){
            if(d[i][idx] == idx - i) cout << "+" << d[i][idx] << '\n';
            else cout << "-" << d[i][idx] << '\n';
        }else{
            if(d[i][idx] == i - idx) cout << "-" << d[i][idx] << '\n';
            else cout << "+" << d[i][idx] << '\n';
        }
        ad++;
        track(0, idx);
        return ;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int s;
    cin >> n >> s;
    s--;
    map < int , int > tm;
    for(int i = 0 ; i < n ; ++i) cin >> a[i], b[i] = a[i];
    sort(b, b + n);
    for(int i = 0 ; i < n ; ++i) if(tm.find(b[i]) == tm.end()) tm[b[i]] = cur++;
    for(int i = 0 ; i < n ; ++i) id[i] = tm[a[i]], cnt[a[i]]++;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j){
            d[i][j] = min({abs(i - j), i + n - j, j + n - i});
            if(i < j) od[i][j] = i + n - j; 
            else od[i][j] = i - j;
        }
    memset(dp, -1, sizeof dp);
    int ans = 1e9, idx = -1;
    for(int i = 0 ; i < n ; ++i) 
        if(!id[i]){
            int sm = solve(0, i) + d[i][s];
            if(sm < ans) ans = sm, idx = i;
        }
    cout << ans <<  '\n';
    if(s <= idx){
        if(d[s][idx] == idx - s) cout << "+" << d[s][idx] << '\n';
        else cout << "-" << d[s][idx] << '\n';
    }else{
        if(d[s][idx] == s - idx) cout << "-" << d[s][idx] << '\n';
        else cout << "+" << d[s][idx] << '\n';
    }
    track(0, idx);
    return 0;
}
