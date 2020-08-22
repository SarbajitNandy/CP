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
	freopen("in.txt","r",stdin);
	int n,t,tmin,ans=0; cin>>n>>t;
	int s,d;                                             
	tmin = numeric_limits<int>::max();
	//cout << tmin	<<endl;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s>>d;
		if (s==t) { ans=i; break;}
		else if (s<t) { 
			s += d*((t-s)/d); 
			if (s<t) { s+=d;} //cout << s<< endl;
			if (s<tmin) { tmin = s; ans=i;} 
		} 
		else {
			if (s>t && s<tmin) { tmin = s; ans = i;}	
		}
		cout << s<< endl;
	}
	cout << ans<< " "<< tmin;
}
