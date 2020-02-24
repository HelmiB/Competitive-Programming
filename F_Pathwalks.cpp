#include<bits/stdc++.h>
using namespace std;
const int maxn = 100500;
const int mod = 1e9 +
struct fw{
    unordered_map<int,int> t;
    int S;
    void clr(int s){S=s,t.clear();}
    void inc(int i,int d){for(;i<S;i|=i+1)t[i] = max(t[i], d);}
    int mx(int i){int s(0);while(~i)s = max(s, t[i]),i&=i+1,--i;return s;}
    int sum(int i){int s(0);while(~i)s+=t[i],i&=i+1,--i;return s;}
    int gt(int l,int r){return sum(r)-sum(l-1);}
};

map<int,fw> T;
void add(int t, int d, fw&F){F.inc(t,d);}
void del(int t,fw&F){F.inc(t,-1);}
int maxi(int t,fw&F){return F.mx(t);}
int gt(int l, int r, fw&F){return F.gt(l, r);}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 0 ; i < m ; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        if(!T.count(u))T[u].clr(maxn);
        if(!T.count(v))T[v].clr(maxn);
        int ad = 1 + maxi(w - 1, T[u]);
        add(w, ad, T[v]);
        ans = max(ans, ad);
    }
    cout << ans << '\n';
    return 0;
}
