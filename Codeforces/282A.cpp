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
	int n,x=0; cin>>n;
	char c[4];
	forf(i,n){
		cin>>c;  //      cout<<c<<endl;
		if (c[0]=='-' || c[2]=='-') x--;
		else x++;		
	}		
	cout<<x;
}
