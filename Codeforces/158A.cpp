#include <iostream>
#include <vector>
using namespace std;
#define int64 long long int
#define vint vector<int>
#define vint64 vector<int64>
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)

int main()
{
	int n,k; cin>>n>>k;
	int a[n];
	forf(i,n){
		cin>>a[i];	
	}		
	// calculation
	int count=0;
	forf(i,n){
		if (a[i]>=a[k-1] && a[i]>0) count++;	
	}
	cout<<count;
	return 0;
}
