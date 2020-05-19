#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
const long double EPS = 1e-14;
const int maxn = 100500;
const int mod = 1e9 + 7;
int start=0,last,point,rem;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    last=s.size()-1;point=s.size();rem=s.size();
	 for(int i = 0; i < s.size(); i++){
    if(s[i] == '.'){
        point = i;
	    s = s.substr(0,i) + s.substr(i+1);}}
	if(point!=rem)last--;
 
	for(;start<s.size();start++)
	    if(s[start]!='0')break;
	s=s.substr(start);last-=start;
    
	while(!s.empty()&&last){
	    if(s[last]!='0')break;last--;}
	
	s=s.substr(0,last+1);
	
	cout<<s[0];
	if(s.size()>1)cout<<'.'<<s.substr(1);
	if(point-start-1!=0)cout<<'E'<<(point-start-1);
    return 0;
}