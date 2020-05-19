#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1050;
const int mod = 1e9 + 7;
int n; 
int a[maxn],s[maxn]; 
bool f[maxn][5000];
int w[maxn][5000],c[maxn][5000]; 
char st[maxn];
 
void init(){
    scanf( "%d" , &n ); 
    for ( int i=1; i<=n; i++ ) scanf( "%d" , &a[i] ); 
    s[0] = 0;
    for ( int i=1; i<=n; i++ ) s[i] = s[i-1] + a[i]; 
}
 
int Lowbit( int x ) { return x & (-x); }
 
void solve(){
    if ( Lowbit( s[n] ) != s[n]){
        printf( "no\n" ); 
        return;
    }
    for ( int i=0; i<=n; i++ ) 
        for ( int j=0; j<=s[i]; j++ ) 
            f[i][j] = false; 
    f[0][0] = true;
    for ( int i=0; i<=n-1; i++ ) {
        int tttt = s[i]/2; 
        for ( int j=0; j<=tttt; j++ ) 
            if ( f[i][j] ) 
            {
                if ( a[i+1] <= Lowbit(s[i]-j) || s[i]-j == 0 ) 
                { f[i+1][j] = true; w[i+1][j] = 'r'; c[i+1][j] = j; }
                if ( a[i+1] <= Lowbit(j) || j == 0 )
                {
                    int temp = j+a[i+1]; 
                    if ( Lowbit(temp) == temp && temp*2 > s[i]-j ) temp = 0; 
                    f[i+1][temp] = true; 
                    w[i+1][temp] = 'l'; 
                    c[i+1][temp] = j; 
                }
            }
    }
    if ( f[n][0] ) 
    {
        int x = 0; 
        for ( int i=n; i>=1; i-- ) 
        {
            st[i] = w[i][x]; 
            x = c[i][x]; 
        }
        for ( int i=1; i<=n; i++ ) printf( "%c" , st[i] ); 
        printf( "\n" );         
    }
    else {
        printf( "no\n" ); 
        return; 
    }
}
 
signed main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int T; 
    scanf( "%d" , &T ); 
    while (T--) 
    {
        init(); 
        solve(); 
    }
    return 0;
}