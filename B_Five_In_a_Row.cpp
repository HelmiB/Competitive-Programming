#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
const int N = 11;
 
char s[N][N];
bool row(int i, int j) {
	if (j + 4 >= 10)
		return false;
	int x = 0, o = 0, e = 0;
	for (int k = 0; k < 5; ++k) {
		if (s[i][j + k] == 'X')
			++x;
		else if (s[i][j + k] == 'O')
			++o;
		else
			++e;
	}
	return e == 1 && o == 0;
}
bool col(int i, int j) {
	if (i + 4 >= 10)
		return false;
	int x = 0, o = 0, e = 0;
	for (int k = 0; k < 5; ++k) {
		if (s[i + k][j] == 'X')
			++x;
		else if (s[i + k][j] == 'O')
			++o;
		else
			++e;
	}
	return e == 1 && o == 0;
}
bool d1(int i, int j) {
	if (i + 4 >= 10 || j + 4 >= 10)
		return false;
	int x = 0, o = 0, e = 0;
	for (int k = 0; k < 5; ++k) {
		if (s[i + k][j + k] == 'X')
			++x;
		else if (s[i + k][j + k] == 'O')
			++o;
		else
			++e;
	}
	return e == 1 && o == 0;
}
bool d2(int i, int j) {
	
	if (i + 4 >= 10 || j - 4 < 0)
		return false;
	int x = 0, o = 0, e = 0;
	for (int k = 0; k < 5; ++k) {
		if (s[i + k][j - k] == 'X')
			++x;
		else if (s[i + k][j - k] == 'O')
			++o;
		else
			++e;
	}
	return e == 1 && o == 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i = 0 ; i < 10 ; ++i)
        for(int j = 0 ; j < 10 ; ++j)
            cin >> s[i][j];
    bool yes = false;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			if (row(i, j) || col(i, j) || d1(i, j) || d2(i, j)) {
				yes = true;
			}
		}
	}
    cout << (yes ? "YES":"NO") << '\n';
    return 0;
}