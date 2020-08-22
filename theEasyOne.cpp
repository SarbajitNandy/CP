#include <bits/stdc++.h>
using namespace std;        
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

#define SIZE 100000
#define MOD 1000000007
#define ull unsigned long long 

int cnt[10];
ull fact[SIZE+9] = {1};

int main()
{
    freopen("in.txt","r",stdin);   	

	fore(i,1,SIZE) { // Factorial calculation
		fact[i] = (fact[i-1] * i) % MOD;		
	}	
	
	int t; cin>>t;
	int l;
	ull ans;
	while (t--) {
		 memset(cnt,0, sizeof(cnt));
		 getchar();
		 l = 0; ans = 0;
		 char c;
		 while (c=getchar(), c!='\n' && c!=EOF) {
		 	cout<<c<< " ";
		 	cout<<endl;
		 	cnt[c-48]++;
		 	l++;
		 }
		 ans = fact[l];
		 cout<<ans<< " " << l <<endl;
		 forf(i,l) {
		 	cout<< i<< "="<<cnt[i]<<endl;
		 	if (cnt[i]!=0) {
		 		ans =  (ans / fact[cnt[i]]) % MOD;
		 	}
		 }

		 cout<<ans;
	}
	return 0;
		

}
                                                  