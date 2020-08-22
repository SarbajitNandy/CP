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

int main() {
	int n,d,e;
	cin >> n >>d >>e ;    e*=5;
	
	//start
	int loop=n/e;
	int use, ans=INT_MAX;
	forf(i,loop+1) {
		use = n-(i*e);
		use %= d;
		ans = min(ans, use);
	}
	cout << ans << endl;
		
}
