#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_bacK(x)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;
#define LIM 2000002

int n,m;

bool vis[LIM];
char dp[LIM];

bool go(int i, int j) {
	if (i>n-1 || j>m-1 || vis[i*m+j] || dp[i*m+j]=='#') return false;

	if (i==n-1 && j==m-1) return true;
	if (i!=0 || j!=0) vis[i*m+j]= true;
	return go(i,j+1) || go(i+1,j);
}



int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// freopen("in.txt", "r", stdin);
	cin >> n >> m ;

	// input 
	forf(i,n) {
		forf(j, m) {
			cin >> dp[i*m+j];
		}
	}

	// forf(i,n) {
	// 	forf(j,m) cout << dp[i*m+j] << " ";
	// 	cout << endl;
	// }

	// start
	if (! go(0,0)) cout << 0;
	else if (! go(0,0)) cout << 1;
	else cout << 2;

}
