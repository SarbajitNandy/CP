#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define int64 long long int
#define vint vector<int>
#define vchar vector<char>
#define vint64 vector<int64>
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)

int main()
{
	int n; cin>>n;
	while (n--)
	{
		char s[100];
		cin>>s; int l = strlen(s);
		if (l>10){
			cout<<s[0]<<l-2<<s[l-1]<<endl;	
		} else {
	        	cout<<s<<endl;
		}	          
	}
	//forf(i,str.size()) cout<<str[i]<<" ";
	return 0;
}
