#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
#define LONG_INT_MAX 0x7fffffffffffffff
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;


vector<int> subset;
int n;

void search(int k) {
	if (k==n+1) {
		//process subsets
		for(auto it : subset) {
			cout << it << " ";
		}
		cout << endl;
	} else {
		// include k in the subsets
		subset.pb(k);
		search(k+1);
		// don't include k in the subset
		subset.pop_back();
		search(k+1);

	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	// n=5;

	// generating subsets

	// search(1);

	// vector<int> per;
	// fore(i,1,3) {
	// 	per.pb(i);
	// }

	// do {
	// 	for(auto item : per) cout << item << " ";
	// 	cout << endl;
	// } while (next_permutation(per.begin(), per.end()));
	std::vector<int> v;
	v.pb(0);
	v.pb(1);
	v.pb(2);
	v.pb(3);
	forf(i,1<<4) {
		bitset<5> s=i;
		for(auto item : v) {
			if (s[item]) { cout << item+1 << " ";}
		} cout << endl;
	}
}
