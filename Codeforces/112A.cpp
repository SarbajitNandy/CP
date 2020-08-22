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
	char a[101],b[101];
	cin>>a>>b;
	int l=strlen(a),f=0;
	forf(i,l){
		if (a[i]>='A' && a[i]<='Z') a[i] += 32;
		if (b[i]>='A' && b[i]<='Z') b[i] += 32;
		if (a[i]>b[i]) {f=1; break;}
		else if (a[i]<b[i]) {f=-1; break;}
	}		
	cout<<f;
	return 0;
}
