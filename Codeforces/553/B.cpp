#include <bits/stdc++.h>
using namespace std;        
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

int main()
{
	int n,m;
	int arr[500][500],x=0;	freopen("in.txt", "r", stdin);
	cin >>n>>m;
	vector<int> l(n,1);
	forf(i,n) {
		forf(j,m) {
			cin >> arr[i][j]; 
		}
		x ^= arr[i][0];
	}
	bool f;
	if (!x) {
		f = 0;
		for(int i=0;i<n;i++) {
			for(int j=1;j<m;j++) {
			 	if (arr[i][j] != arr[i][0]) {
			 		f = 1; l[i]=j+1;
					break;
				}
			}  
			if (f) { break;}                                
		}
		if (!f) { cout << "NIE\n"; return 0;}
	}
	
	if (f) {
		cout << "TAK\n";
		for(auto i=l.begin(); i!=l.end(); i++) {
			cout << *i << " ";
		}
	} 

}
