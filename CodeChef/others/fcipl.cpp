#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
 
#define pb(x) push_bacK(x)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;
const long MAX = 1e9+7;

int64 const MOD = 998244353;

int64 dpFoot[109][109];
int64 dpCrick[109][109];

int64 goFoot(int64 n ,int64 r) {
	if (n<r) return 0;
	else if (r==1) return 1;
	else if (dpFoot[n][r]!=-1) return dpFoot[n][r];
	else {
		dpFoot[n][r] = ((r*goFoot(n-1,r))%MOD + goFoot(n-1,r-1))%MOD;
		return dpFoot[n][r];	
	}
	
}

int64 goCrick(int64 n, int64 r) {
	if (n<=r) return 0;
	else if (r==1) return 1;
	else if (dpCrick[n][r]!=-1) return dpCrick[n][r];
	else {
		dpCrick[n][r] = ((r*goCrick(n-1,r))%MOD + ((n-1)* goCrick(n-2,r-1))%MOD)%MOD;
		return dpCrick[n][r];
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	// memset
	memset(dpFoot, -1, sizeof(dpFoot));
	memset(dpCrick, -1, sizeof(dpCrick));

	int64 t; cin >> t;
	int64 p,q,r;
	int64 c;
	while (t--) {
		cin >> p >> q >> r;
		c=0;

		for(int i=1;i<r; i++) {
			c+= (goFoot(p,i) * goCrick(q,r-i))%MOD;
			c=c%MOD;
		}

		cout  << c << endl;

	}

}
