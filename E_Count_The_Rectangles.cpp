#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 10050;
const int mod = 1e9 + 7;
bool in[maxn];

struct BIT{
    private: long long tree[maxn + 10];
    public:
    void add(int x, long long v = 1){for(x++; x < maxn; x += x & -x)tree[x] += v;}
    long long get(int x){long long ret = 0; for(x++; x; x -= x & -x)ret += tree[x]; return ret;}
    int range(int l, int r){
        if(l > r) return 0;
        return get(r) - (l > 0 ? get(l - 1):0);
    }
}bit;

struct Segment{
    int x1, y1, x2, y2;
}seg[maxn];

vector < int >  max_y[maxn], min_y[maxn];

inline bool cmp(const int &a, const int &b){
    return seg[a].y2 > seg[b].y2;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector < int > hor;
    for(int i = 0 ; i < n ; ++i){
        cin >> seg[i].x1 >> seg[i].y1 >> seg[i].x2 >> seg[i].y2;
        seg[i].x1 += 5000;
        seg[i].x2 += 5000;
        seg[i].y1 += 5000;
        seg[i].y2 += 5000;
        if(seg[i].y1 > seg[i].y2){
            swap(seg[i].y1, seg[i].y2);
            swap(seg[i].x1, seg[i].x2);
        } 
        if(seg[i].x1 == seg[i].x2){
            max_y[seg[i].y2].push_back(i);
            min_y[seg[i].y1].push_back(i);
        }else{  
            hor.push_back(i);
        }
    }
    int ans = 0;
    sort(all(hor), cmp);
    for(int i = 0 ; i < sz(hor) ; ++i){
        for(int j = 0 ; j < n ; ++j)
            if(in[j]){
                in[j] = false;
                bit.add(seg[j].x1, -1);
            }

        int maxi = maxn - 1;
        while(maxi >= seg[hor[i]].y2){
            for(auto x : max_y[maxi]){
                assert(!in[x]);
                bit.add(seg[x].x1, 1);
                in[x] = true;
            }
            maxi--;
        }
        int mini = maxn - 1;
        while(mini > seg[hor[i]].y2){
            for(auto x : min_y[mini]){
                assert(in[x]);
                bit.add(seg[x].x1, -1);
                in[x] = false;
            }
            mini--;
        }
        int a = seg[hor[i]].x1, b = seg[hor[i]].x2;
        for(int j = i + 1 ; j < sz(hor); ++j){
            if(seg[hor[j]].y2 == seg[hor[i]].y2) continue;
            while(mini > seg[hor[j]].y2){
                for(auto x : min_y[mini])
                    if(in[x]){
                        in[x] = false;
                        bit.add(seg[x].x1, -1);
                    }
                mini--;
            }
            int c = seg[hor[j]].x1, d = seg[hor[j]].x2;
            if(a > b) swap(a, b);
            if(c > d) swap(c, d);
            int x = bit.range(max(a, c), min(b, d));
            ans += x * (x - 1) / 2;
        }
    }
    cout << ans << '\n';
    return 0;
}