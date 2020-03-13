#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
bool done[2 * maxn];
int p[2 * maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    set < int > in;
    for(int i = 1 ; i <= n ; ++i){
        cin >> p[i];
        done[p[i]] = true;
    }
    for(int i = 1 ; i <= n ; ++i)
        if(!done[i])
            in.insert(i);
    for(int i = 1 ; i <= n ; ++i)
        if(!p[i] && in.find(i) != in.end()){
            if(sz(in) == 1){
                p[i] = *in.begin();
                in.erase(p[i]);
            }else{
                if(i != *in.begin()){
                    p[i] = *in.begin();
                    in.erase(p[i]);
                }else{
                    p[i] = *in.rbegin();
                    in.erase(p[i]);
                }
            }
        }
    for(int i = 1 ; i <= n ; ++i)
        if(!p[i]){
            p[i] = *in.begin();
            in.erase(p[i]);
        }
    for(int i = 1 ; i <= n ; ++i) cout << p[i] << ' ';
    cout << '\n';
    return 0;
}
