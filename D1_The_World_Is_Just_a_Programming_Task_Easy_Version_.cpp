#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int bal = 0;
    int ans = 0, l = 1, r = 1;
    for(auto c : s) bal += (c == '(' ? 1:-1);
    if(bal) return cout << "0\n1 1\n", 0;
    for(int i = 0 ; i < n ; ++i)
        for(int j = i + 1 ; j < n ; ++j){
                string t = s;
                swap(t[i], t[j]);
                int mn = n + 1;
                bal = 0;
                for(auto c : t){
                    bal += (c == '(' ? 1:-1);
                    mn = min(mn, bal);
                }
                int idx = -1;
                if(mn >= 0) idx = 0;
                int pre = 0, mnpre = n + 1;
                for(int i = 0 ; i < n && idx == -1 ; ++i){
                    if(t[i] == '(') pre++, mn--;
                    else pre--, mn++;
                    mnpre = min(mnpre, pre);
                    if(mn >= 0 && pre <= 0 && -pre + mnpre >= 0){
                        idx = i + 1;
                        break;
                    }
                } 
                if(idx == -1) continue;
                string tmp = "";
                for(int i = idx ; i < n ; ++i) tmp += t[i];
                for(int i = 0 ; i < idx ; ++i) tmp += t[i];
                int cnt = 0, bal = 0;
                for(auto c : tmp){
                    bal += (c == '(' ? 1:-1);
                    if(!bal) cnt++;
                }
                if(ans < cnt){
                    ans = cnt;
                    l = i + 1;
                    r = j + 1;
                }
            }
    cout << ans << '\n';
    cout << l << ' ' << r << '\n';   
    return 0;
}
