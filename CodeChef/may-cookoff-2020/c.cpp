#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_back(x)
#define mk(x) make_pair(x)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
#define LONG_INT_MAX 0x7fffffffffffffff

typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

map<int,int> M;
vector<int> o,e;

int n,m;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("in.txt", "r", stdin);	
	freopen("out.txt", "w", stdout);

	int t; cin >> t;	
	while (t--) {
		cin >> n >>m ;
		int arr[n][m];

		forf(i,n) {
			forf(j,m) {
				cin >> arr[i][j];
				M[arr[i][j]]++;
			}
		}

		// show M 
		// for(auto x : M) {
		// 	cout << x.first << " " << x.second << endl;
		// }

		int odd=0;

		for(auto item : M ) {
			forf(i,item.second/2) e.pb(item.first);
			if (item.second&1) { o.pb(item.first); odd++;}
		}

		// for(auto i: e) cout << i << " "; cout << endl;
		// 	for(auto i: o) cout << i << " "; cout << endl;

		if ((m%2==0 && o.size()>0) || (m%2!=0 && o.size()>n)) cout << -1 << endl;
		else {
			while (m&1 && o.size()!=n) {
				o.pb(e.back());
				o.pb(e.back());
				e.pop_back();
			}
			for(int x : o) e.pb(x);
			int front=0;
			int back = e.size()-1;
			forf(i,n) {
				forf(j,m/2) {
					arr[i][j]=arr[i][m-j-1]=e[front]; front++;
				}
				if (m&1) {
					arr[i][m/2]=e[back]; back--;
				}
			}

			forf(i,n) {
				forf(j,m) cout << arr[i][j] << " " ;
				cout << endl;
			}
		}

		M.clear();
		o.clear(); e.clear();
		

	}

	

}


// 1 2 3 4
// 2 1
// 1 
// 2
// 3 5
// 1 2 3 2 1
// 7 4 7 4 7
// 3 2 7 2 3
// 3 5
// 1 2 3 2 1
// 2 3 7 3 2
// 7 7 3 7 7