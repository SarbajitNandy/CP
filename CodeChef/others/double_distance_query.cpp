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

const int N = 1e3;

int arr[N][N];
int height[N];
int n;

int stepDown(int node, int step) {
	bool flag;
	forf(j,step) {
		flag=false;
		for(int i=node+1;i<=n;i++) {
			if (arr[node][i]) {
				flag=true;
				node=i; break;
			}
		} 
		if (!flag) return -1;
	}

	return node;

}

int stepUp(int node, int step) {
	bool flag;
	forf(_,step) {
		flag=false;
		for(int i=1;i<node;i++) {
			if (arr[i][node]) {
				flag=true;
				node=i; break;
			}
		} 
		if (!flag) return -1;
	}

	return node;
}

int findAll(int node, int step) {
	
}

int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t; cin >> t;

	int q; cin >> n >> q;
	int u,v;
	cin >> u>>v;
	height[u]=0;
	height[v]=height[u]+1;
	arr[u][v]=1;
	arr[v][u]=1;
	for(int i=1;i<n-1;i++) {
		cin >> u >>v ;
		height[v] = height[u]+1;
		arr[u][v]=1;
		arr[v][u]=1;
	}

	for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			cout << arr[i][j] << " ";
		} cout << endl;
	}

	for(int i=0;i<=n;i++) cout << height[i]<< " ";

	int a,da, b, db;
	int mx,mn,mxd,mnd;
	while (q--) {
		cin >> a>> da >> b >> db;
		cout << "ans";
		if (height[a]>height[b]) {
			mx=a; mxd=da;
			mn=b; mnd=db;
		} else {
			mx=b; mn=a;
			mxd=db; mnd= da;
		}
		if (mx-mn==mxd+mnd) {
			int ans = stepDown(mn,mnd);
			if (ans==stepUp(mx,mxd)) {
				cout << ans;
			}
		} else if (mx-mn<mxd+mnd) {
			if (mxd > mnd) {
				int ans = stepUp(mn,mnd);
				if (ans==stepUp(mx,mxd)) {
					cout << ans;
				} 
			} else if (mxd > mnd) {
				int ans = stepDown(mn,mnd);
				if (ans==stepDown(mx,mxd)) {
					cout << ans;
				}

			} else {
				cout << -1 << endl;
			}
		} else {
			cout << -1 << endl;
		}
	}

	

}
