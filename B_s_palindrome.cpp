#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
vector < int > a[250];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    map< char, char > M;
	M['A'] = 'A';
	M['b'] = 'd';
	M['d'] = 'b';
	M['H'] = 'H';
	M['I'] = 'I';
	M['M'] = 'M';
	M['O'] = 'O';
	M['o'] = 'o';
	M['p'] = 'q';
	M['q'] = 'p';
	M['T'] = 'T';
	M['U'] = 'U';
	M['V'] = 'V';
	M['v'] = 'v';
	M['W'] = 'W';
	M['w'] = 'w';
	M['X'] = 'X';
	M['x'] = 'x';
	M['Y'] = 'Y';
    string s;
    cin >> s;
    int i = 0, j = sz(s) - 1;
    while(i < j){
        if(M[s[i]] != s[j]) return cout << "NIE" << '\n', 0;
        i++; j--;
    }
    if(i == j && M[s[i]] != s[i]) return cout << "NIE" << '\n', 0;
    cout << "TAK" << '\n';
    return 0;
}