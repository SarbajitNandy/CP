#include <bits/stdc++.h>
using namespace std;        
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;
#define LARGE 1000000007

int64 arr[1000000],k=1;

int main()
{
	int t,n;
	cin >> t ;
	while (t--) {
		cin >> n;
		if (n<=k-1) { cout << arr[n]<<endl;}
		else {
			for(;k<=n;k++){
				arr[k] = (arr[k-1] + k + k*arr[k-1])%LARGE;
			}
			cout << arr[n] << endl;
		}
	}		
}
 