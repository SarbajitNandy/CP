#include <bits/stdc++.h>
using namespace std;
#define int64 long long int
#define vint vector<int>
#define vint64 vector<int64>
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)

const int64 m = 1e9 + 7,N = 1e7;

/*                         Generic solution with dynamic programming for all vertices
int dp[4][N];
bool vis[4][N];
void print(int64 &n)
{
	cout<<"Dp matrix: \n";
	forf(i,4){
		forf(j,n){
			cout<<dp[i][j]<<" ";			
		}
		cout<<endl;
	}
}
       
int go(int src,int des, int step){
	if (step==0){
		if (src==des) return 1;
		else return 0;
	}
	int &ans = dp[src][step];
	if (vis[src][step])
		return dp[src][step];	
	vis[src][step] = true;
	forf(i,4){
		if (i==src) continue;
		ans+=go(i,des,step-1);
		if (ans>=m) ans-=m;
	}	
	return ans;
} 
                                                                                                    
int main()
{
	freopen("in.txt","r",stdin);
	int64 n; cin>>n;
	cout<<go(1,1,n)<<endl;
	print(n);		
}
*/

/*										Dynamic programming with more optimized format

int dp[2][N];
bool vis[2][N];

int go(int same, int step){
	if (!step){
		if (same) return 1;
		return 0;
	}
	
	int &ans = dp[same][step];
	if (vis[same][step]) return ans;
	vis[same][step] = true;
	if (same)
		return ans = (3*go(1-same,step-1))%m;
	else return ans = (2*go(0,step-1)+go(1,step-1))%m;
}

int main()
{
	freopen("in.txt","r",stdin);
	int64 n; cin>>n;
	cout<<go(0,n)<<endl;
	//print(n);		
}  
*/

//                                             Same solution with loop structure avoiding recursion

int dp[2][N+1];
//bool vis[2][N+1];
#define ll long long 
void print(int &n)
{
	cout<<"Dp matrix: \n";
	forf(i,2){
		forf(j,n+1){
			cout<<dp[i][j]<<" ";			
		}
		cout<<endl;
	}
}
 

int main()
{
    freopen("in.txt","r",stdin);
	int n; cin>>n;
	dp[1][0] = 1;
	fore(i,1,n){
		dp[1][i] = (3ll*dp[0][i-1]) %m;       // More to explore the idea
		dp[0][i] = (2ll*dp[0][i-1] + dp[1][i-1]) % m;
	}	
	cout<<dp[1][n];
	//print(n);
	return 0;

}



