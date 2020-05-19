#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1000500;
const int mod = 1e9 + 7;
int p[maxn], q[maxn];
bool vis[maxn];
vector < vector < int > > od;
vector < pair < int, vector < int > > >   ev;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i) cin >> p[i], p[i]--;
    for(int i = 0 ; i < n ; ++i)
        if(!vis[i]){
            int cur = i;
            vector < int > c;
            while(!vis[cur]){
                vis[cur] = true;
                c.push_back(cur);
                cur = p[cur];
            }
            if(sz(c) & 1) od.push_back(c);
            else ev.push_back({sz(c), c});
        }
    if(sz(ev) % 2) return cout << -1 << '\n', 0;
    sort(all(ev));
    for(int i = 0 ; i < sz(ev) ; i += 2)
        if(ev[i].first!= ev[i + 1].first) return cout << -1 << '\n', 0;
        else{
            int prv = ev[i + 1].second[sz(ev[i].second) - 1];
            for(int j = 0 ; j < sz(ev[i].second); ++j){
                q[prv] = ev[i].second[j] + 1;
                q[ev[i].second[j]] = ev[i + 1].second[j] + 1;
                prv = ev[i + 1].second[j];
            }
            q[prv] = ev[i].second[0] + 1;
        }
    for(auto c : od){
        int mid = sz(c) / 2;
        for(int i = 0 ; i < sz(c) ; i++)
            if(i <= mid) q[c[i]] = c[(i + mid + 1) % sz(c)] + 1;
            else q[c[i]] = c[i - mid] + 1;
    }
    for(int i = 0 ; i < n ; ++i) cout << q[i] << ' ';
    cout << '\n';
    return 0;
}
