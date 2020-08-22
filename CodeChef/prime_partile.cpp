#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
 
#define pb(x) push_bacK(x)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int ll;
typedef vector<int> vint;
typedef vector<ll> vint64;
const long MAX = 1e9+7;

ll n,q;
bool prime[1000002];

void buildPrime() {

	prime[0] = prime[1] = true;

	fore(i,2,n+1) {
		if (!prime[i])
		{
			for (int j = i+i; j <= n; j=j+i)
			{
				prime[j]=true;
			}
		}
	}
}

int findMinPrime(ll val) {
	fore(i,2,n-1) {
		if (!prime[i] && val%i==0)
		{
			return i;
		}
	}
	return -1;
}

int go(ll a, ll b) {
	if (a>b) swap(a,b);
	// cout << a << " " << b << endl;
	// if (b>n) return -1;
	if (a==b) return 0;

	if ( !prime[a] && !prime[b] ) {
		if (a*b > n ) {
			if (b*2 > n) return -1;
			else return 4;
		}
		else return 2;
	}

	else if (prime[a] && prime[b]) 
	{
		int gcd = __gcd(b,a);
		if (gcd==1) { // co prime
			return 4;
		}
		return 2;
	}


	else {
		if(!prime[b])swap(a, b); //cout << a << " " << b << endl;
		if( (b%a)==0 ) { return 1; }
		else { int x = go(a, findMinPrime(b)); return (x==-1)?(-1):(x+1); }
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	cin >> n >> q; buildPrime();
	int a,b;

	// forf(i,n+1) cout << i<< "= " << prime[i] << endl;

	while (q--) {
		cin >> a >> b;

		cout << go(a,b) << endl;

	}
}

	// if (!prime[a] && b%a==0) return 1;

	// if (!prime[a] && prime[b]) {	//false  -> prime, true-> not prime

	// 	if (b%a==0) return 1;
	// 	else {
	// 		ll pDiv = findMinPrime(b);  //cout << pDiv << endl;
	// 		// if (pDiv < a) swap(pDiv,a);
	// 		if (a*pDiv > n) {
	// 			if ( max(a,pDiv)*2 > n ) return -1;
	// 			else return 4;
	// 		}
	// 		else return 3;
	// 	}
	// }

	// if( prime[a] && !prime[b]) {
	// 	ll pDiv = findMinPrime(a); //cout << pDiv << endl;
	// 	if (pDiv*b > n) {
	// 		if (max(pDiv,b)*2 > n) return -1;
	// 		else return 4;
	// 	}
	// 	else return 3;
	// }