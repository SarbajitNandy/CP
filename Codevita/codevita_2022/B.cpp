#include <bits/stdc++.h>
using namespace std;
int getNumberOfPrime(int length, vector<bool>& prime){
	int ans = 0;
	for(int i=1;i<=length;i++){
		if (prime[i])ans++;
	}
	// cerr << "for " << length << ": ans "<< ans << endl;;
	return ans;
}

void solve()
{
	int n; cin>> n; //cout << n << endl;
	vector<bool> prime(n+1, true);
	prime[1]=false;
	for(int p=2;p*p<=n;p++){
		if(prime[p]) {
			for(int i=p*p;i<=n;i+=p) prime[i]=false;
		}
	}

	// for(int i=0;i<=n;i++) cout << prime[i] << " ";
	// cout << endl;
	int l=n; //cout << l << endl;
	int ans=0;
	while(l!=1) {
		int s= getNumberOfPrime(l,prime);
		// cout << s << endl;;
		l-=s;
		// cerr << l << endl;
		ans++;
	}

	cout << ans+1;

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int t = 1;
    while (t--) {
        solve();
        cout << '\n';
    }
 
    return 0;
}
