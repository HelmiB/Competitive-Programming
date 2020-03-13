#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int a[1010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int ad = 0;
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    sort(a, a + n);
    vector < int > pile;
    for(int i = 0 ; i < n ; ++i){
        int idx = -1, best = -1;
        for(int j = 0 ; j < sz(pile) ; ++j)
            if(pile[j] <= a[i] && pile[j] > best)
                idx = j, best = pile[j];
        if(~idx) pile[idx]++;
        else pile.push_back(1);
    }
    cout << sz(pile) << '\n';
    return 0;
}
