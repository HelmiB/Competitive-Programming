
#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 1000500;
const int mod = 1e9 + 7;
string  pat;
int m, f[maxn];

void failure(){
    f[0] = 0;
    for(int i = 1 ; i < m ; ++i){
        int k = f[i - 1];
        while(k > 0 && pat[k] != pat[i]) k = f[k - 1];
        if(pat[k] == pat[i]) f[i] = ++k;
        else f[i] = k;
        int len = i + 1;
        if(f[i] && len % (len - f[i]) == 0){
            cout << i + 1 << ' ' << len / (len - f[i]) << '\n';
        }
    }
}

function Knuth_Morris_Pratt(text[], pattern[])
{
  // let n be the size of the text, m the // size of the pattern, and F[] - the// "failure function"

  build_failure_function(pattern[]); 

  i = 0; // the initial state of the automaton is// the empty string

  j = 0; // the first character of the text
  
  for( ; ; ) {
    if(j == n) break; // we reached the end of the text
    // if the current character of the text "expands" the
    // current match
     if(text[j] == pattern[i]) {
      i++; // change the state of the automaton
      j++; // get the next character from the text
      if(i == m) // match found
    }
    else if(i > 0) i = F[i];

    // if the current state is not zero (we have not// reached the empty string yet) we try to
    // "expand" the next best (largest) match

    // if we reached the empty string and failed to// "expand" even it; we go to the next // character from the text, the state of the// automaton remains zeroelse j++;
  }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int tc = 1 ; tc <= t ; ++tc){
        cout << "Test case # " << tc << '\n';
        cin >> m >> pat;
        failure();
        cout << '\n';
    }
    return 0;
}