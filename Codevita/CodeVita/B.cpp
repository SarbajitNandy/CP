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
		int64 n,m;
		int64 t;
		int t1;
		cin >> t1;
		while ( t1--){
			cin >> n >>m ;
			if ( m>n) {
				t = m; m = n; n = t;
			}

			if (n%m == 0) {
				cout << 0;
			} else {
				while ( m!=0) {
					t = m;
					m = n%m;
					n = t;
				}
				cout << n ;	
			}
		}
		
		return 0;
}
