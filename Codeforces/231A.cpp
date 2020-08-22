#include <bits/stdc++.h>
using namespace std;
#define int64 long long int
#define vint vector<int>
#define vint64 vector<int64>
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)

int main()
{
	freopen("in.txt","r",stdin);
	int n,count=0,a;cin>>n;
	forf(i,n){
		int c=0;
		forf(j,3){
			cin>>a;cout<<a;
			if (a==1) {c++;}
		}
	 	cout<<endl<<c<<endl;
		if (c>=2) {count++;}
	}		
	cout<<count;
	return 0;
}
