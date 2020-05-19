#include <bits/stdc++.h>
using namespace std;

int n,fingers=0;
int a[105];
 
int main()
{

    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        fingers+=a[i];
    }
	
    for(int i=1;i<5;++i)
    {
        if((fingers+i)%(n+1)!=1) 
        {cout<<i<<"\n";
        break;}
    }


	return 0;
}