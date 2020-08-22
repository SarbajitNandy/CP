#include <bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
#define pb(x) push_back(x)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

int main()
{

	int n,m; cin >>n >>m;
	int arr[n][m];
	int count=0;
	vector<pair<int,int>> ans;
	bool is_zero= true;
	
	// taking input

	forf(i, n)
	forf(j, m) {
		cin >> arr[i][j];
		if ( arr[i][j] ) { is_zero = false; count++; }
	}	

	if (is_zero) { cout << 0 << endl; return 0; }
	else {
		forf(i, n-1) {
			forf(j, m-1) {
				if ( arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1] ) {
					ans.push_back({ i+1, j+1 }); 
	                if (arr[i][j] == 1) { arr[i][j]=2; count--; }
	                if (arr[i][j+1] == 1) { arr[i][j+1]=2; count--; }
	                if (arr[i+1][j] == 1) { arr[i+1][j]=2; count--; }
	                if (arr[i+1][j+1] == 1) { arr[i+1][j+1]=2; count--; }
	                //cout << endl << print(arr);
/*	                forf(i,n) {
					forf(j,m)  cout << arr[i][j] << " ";
					cout << endl;
					}
					cout << endl;
*/				}
			}
		}
	}

	// Answer section
	if (! count) {  
		cout << ans.size() << endl;
		for(auto x : ans) { cout << x.first << " " << x.second << endl; }
	} else {
		cout << -1 << endl;
	}
}
