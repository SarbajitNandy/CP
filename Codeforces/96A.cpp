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
	char ar[101];
	int s=7,f=0;
	cin>>ar;
	int l = strlen(ar);
	forf(i,l-1){     
		if (ar[i]=='0'){
			if (i!=0 && ar[i-1]=='1') s=7;
			if ((--s)==0) f=1;
		}
		else {
			if (i!=0 && ar[i-1]=='0') s=7;
			if ((--s)==0) f=1;			
		} 
	}
	if (f) cout<<"YES";
	else  cout<<"NO";
	return 0;

}
