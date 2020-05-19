#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int n, m;

bool isEleminte(int **A, int x, int y){
	long double ele = A[x][y];
	long double up = 0, cnt = 0;
	long double down = 0;
	long double left = 0;
	long double right = 0; 
	for (int i = x+1; i < n; ++i){
		if(A[i][y] == 0) continue;
		cnt++;
		down = A[i][y];
		break;
	}
	for (int i = x-1; i >= 0; --i){
		if(A[i][y] == 0) continue;
		cnt++;
		up = A[i][y];
		break;
	}

	for (int i = y+1; i < m; ++i){
		if(A[x][i] == 0) continue;
		cnt++;
		right = A[x][i];
		break;
	}
	for (int i = y-1; i >= 0; --i){
		if(A[x][i] == 0) continue;
		cnt++;
		left = A[x][i];
		break;
	}

	if(cnt != 0){
		long double avg = (left + right + up + down) / cnt;
		return (ele < avg);
	}
	else {
		return false;
	}

}


void solve(){
	cin >> n >> m;
	int **A = new int *[n];
	for (int i = 0; i < n; ++i)
		A[i] = new int[m];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> A[i][j];

	bool flag = false;
	ll sum = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j)
			sum += A[i][j];
	}

	int times = 3;
	while(!flag){
		flag = true;
		vector<pair<int, int> > eliminated;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				if(A[i][j] == 0) continue;

				if(isEleminte(A, i, j)){
					flag = false;
					eliminated.push_back({i, j});
				}
			}
		}

		for (auto i: eliminated){
			A[i.first][i.second] = 0;
			
		}
		if(!flag){
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j){
				sum += A[i][j];
			}
		}
	}

	cout << sum << endl;

}


int main(){
	
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	#ifndef ONLINE_JUDGE
       //faster compilation    
	#endif
	

    int r; cin >> r;
    for (int j = 1; j <= r; ++j){
    	cout << "Case #" << j << ": ";
    	solve();
    }



	

	return 0;
}
