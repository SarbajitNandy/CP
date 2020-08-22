#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_back(x)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

const int N = 10e4 + 1;
vector<int> dp[N];
int arr[N];
int n,k,m;

int check_index(int a) {
	int index = a %m;
	return index ==0 ? m : index;
}

int back_track(int pos, int old_val) {

	int index = check_index(pos);
	// vector<int> &data = dp[pos];
	
	if (pos == k ) {
		vector<int>::iterator it = dp[index].begin();
		int len = dp[index].size() - (int)(upper_bound(dp[index].begin(), dp[index].end(), old_val) - it );
		// cout << "len " << len << endl;
		return len;
	}
	else {
		// cout << " else" << endl;int n,k,m;
		int res = 0;
		for (auto item: dp[index]) {
			if ( item > old_val) {
				// cout << "item " << item << endl;
				res += back_track(pos+1, item);
			}
		}
		return res;
	}


}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t; cin >> t;

	int val;
	while (t--) {
		cin >> n >> k >> m;

		for (int i = 0; i < n; ++i)
		{
			/* code */
			cin >> val;
			dp[check_index(val)].pb(i);
		}

		// for(int i=1;i<=m;i++) {
		// 	cout << i << " ->";
		// 	for(auto item: dp[i]) {
		// 		cout << item << " ";
		// 	}
		// 	cout << endl;
		// }

		cout << back_track(1, -1) << endl;

		memset(dp, 0 , sizeof(dp));

	}
}
