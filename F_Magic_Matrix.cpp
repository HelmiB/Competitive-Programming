#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
bitset < 2501 > b[2501];
int a[2501][2501];


void NO(){
    cout << "NOT MAGIC\n";
    exit(0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < n ; ++j)
            cin >> a[i][j];
        for(int i = 0 ; i < n ; ++i)
            if(a[i][i])
                NO();
        vector < pair < int, pair < int, int > > > v;
        for(int i = 0 ; i < n ; ++i)
            for(int j = 0 ; j < i ; ++j)
                if(a[i][j] != a[j][i]) NO();
                else v.push_back({a[i][j], {i, j}}), v.push_back({a[i][j], {j, i}});
        sort(all(v));
        int i = 0;
        while(i < sz(v)){
            int j = i;
            while(j < sz(v) && v[i].first == v[j].first){
                if((b[v[j].second.first] & b[v[j].second.second]).any()) NO();
                ++j;
            }
            for(int k = i ; k < j ; ++k)
                b[v[k].second.first].set(v[k].second.second);
            i = j;
        }
        cout << "MAGIC\n";
    return 0;
}