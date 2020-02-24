#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> pi4;
// 0 = R, 1 = G, 2 = Y, 3 = B
char a[510][510];
int cnt[4][510][510];
unsigned short exist[252][510][510];
// first dim halved

int query(int col, int up, int left, int sz) {
    return cnt[col][up+sz-1][left+sz-1] -
           cnt[col][up+sz-1][left-1] - cnt[col][up-1][left+sz-1] +
           cnt[col][up-1][left-1];
}

int query2(int sz, int up, int left, int down, int right) {
    cout << exist[sz][down][right] << ' ' << exist[sz][up-1][right] << ' ' << exist[sz][down][left-1] << ' ' << exist[sz][up-1][left-1] << '\n';
    return exist[sz][down][right] - exist[sz][up-1][right] -
           exist[sz][down][left-1] + exist[sz][up-1][left-1];
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> a[i][j];

    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
        cnt[0][i][j] = cnt[0][i-1][j] + (a[i][j]=='R');
        cnt[1][i][j] = cnt[1][i-1][j] + (a[i][j]=='G');
        cnt[2][i][j] = cnt[2][i-1][j] + (a[i][j]=='Y');
        cnt[3][i][j] = cnt[3][i-1][j] + (a[i][j]=='B');
    }

    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
        cnt[0][i][j] += cnt[0][i][j-1];
        cnt[1][i][j] += cnt[1][i][j-1];
        cnt[2][i][j] += cnt[2][i][j-1];
        cnt[3][i][j] += cnt[3][i][j-1];
    }

    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
        //if (a[i][j]!='R') continue;
        int mx = 0;
        for (int k=1;k<=n;k++) {
            if (i+2*k-1>n||j+2*k-1>m) break;
            int req = k*k;
            int R = query(0, i, j, k);
            int G = query(1, i, j+k, k);
            int Y = query(2, i+k, j, k);
            int B = query(3, i+k, j+k, k);
            if (R==req&&G==req&&Y==req&&B==req) mx = k;
        }
        exist[mx][i][j] = 1;
    }
    
    for (int i=0;i<=250;i++) {
        for (int j=1;j<=n;j++) {
            for (int k=1;k<=m;k++) {
                exist[i][j][k] += exist[i][j-1][k];
            }
        }
    }
    for (int i=0;i<=250;i++) {
        for (int j=1;j<=n;j++) {
            for (int k=1;k<=m;k++) {
                exist[i][j][k] += exist[i][j][k-1];
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j)
            cout << exist[1][i][j] <<' ';
        cout << '\n';
    }
    cout << "-------------------\n";
    cout << query2(1, 1, 1, 4, 4) << '\n';
    return 0; 
    /*for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
        cout << exist[1][i][j] << " \n"[j==m];
    }*/

    int lim = min(n/2, m/2);
    for (int i=0;i<q;i++) {
        int r1, r2, c1, c2; cin >> r1 >> c1 >> r2 >> c2;
        int ans = 0;
        int l = 0, r = lim+1;
        while (l+1<r) {
            int sz = (l+r)>>1;
            int now_r2 = r2+1-2*sz, now_c2 = c2+1-2*sz;
            if (now_r2<r1||now_c2<c1) {
                r = sz;
                continue;
            }
            int cnt = query2(sz, r1, c1, now_r2, now_c2);
            if (cnt) l = sz; else r = sz;
        }
        cout << 4*l*l << "\n";
    }
}
