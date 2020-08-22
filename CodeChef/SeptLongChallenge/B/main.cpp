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

int dp[51][51];

int go(int n,int r) {
	// cout << n << " " << r << endl;
    if ( dp[n][r]!=0 || r==0 || n==0) { return dp[n][r]; }
    for(int i=0;i<=n;i++) {
        for(int j=min(i,r); j>=1;j--) {
            if (dp[i][j] != 0 ) { continue; }
            else if ( i==j) { dp[i][j]=1;}
            else {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }
    return dp[n][r];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("out.txt", "w", stdout);
	for(int i=0;i<52;i++) { dp[i][0]=1; }
	int t; cin >> t;
	int n,k,val;

	map<int , int> map;
	while (t--) {
		cin >> n >> k; 
		forf(i, n) {
			cin >> val;
			map[val]++;
		}

		// for(auto x: map) cout << x.first  << " " << x.second << endl;
		int p=0,ttl=0;
		for(auto x: map) {
			ttl = x.second;
			if (p+x.second>k) break;
			p+=x.second;
		}

		cout << go(ttl, min(k-p, ttl-k+p) ) << endl;   // k-p
		map.clear();

	}


}
