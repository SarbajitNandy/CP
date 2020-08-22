#include <bits/stdc++.h>
using namespace std;        
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
#define int64 long int
typedef vector<int> vint;
typedef vector<int64> vint64;
#define LARGE 1000000007

int main()
{
	freopen("in.txt","r",stdin);	
	int i,t; 
	long long int n,m;
	cin >> t;
	while (t--){
		cin >> n>>m; i=0;
		cout << n << " "<< m<<endl;
		//cout << "n: "<<n<<"m: "<<m<<endl;
		if (n==m) { cout << "Ari\n"; }
		else {
			while ( n!=0 && m!=0) {
				if (n>m) {
					n %= m;
				} else {
					m %= n;
				}
				i++; 
				cout << n << " "<< m<<endl;
			}
			cout << i<<endl;
			if (i%2==0) { cout << "Rich\n";}	
			else  { cout << "Ari\n";}	
		}
	}
	return 0;

}
 