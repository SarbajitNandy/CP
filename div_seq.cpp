#include <bits/stdc++.h>
using namespace std;
#define int64 long long int
#define vint vector<int>
#define vint64 vector<int64>
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)

int dp[2500];

int main()
{
	//freopen("in.txt","r",stdin);
	int n; cin>>n;
	int a[n];
	forf(i,n) cin>>a[i];
	//calculation
	forb(i,n){
		fore(j,i+1,n-1){
			if (a[j]%a[i]==0 && i!=n-1){
				//cout<<a[j] <<"/"<<a[i]<<" "<<dp[j]+1<<endl;
				if (dp[i]<dp[j]) dp[i]=dp[j];
			}
		}
		dp[i]++;
	}
	cout<<endl;	
	// printing dpd result
	forf(i,n) cout<<dp[i]<<" ";
	return 0;		
}
