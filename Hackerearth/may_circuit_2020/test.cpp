#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

const int N = 1e5+1;
vector<int> graph[N];
// vector<int> tree[N];
bool tree[N][26];
char name[N];
bool vis[N];
void dfs(int root) {
	// int root = 1;
	vis[root]=1;
	for ( auto child : graph[root]) {
		if (!vis[child]) {
			dfs(child);
			for(int i=0;i<26;i++){
				if (tree[child][i]) tree[root][i]=1;
			}
		}
	}
	tree[root][name[root]-91]=1;
}

int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n,q ; cin >> n >> q;
 
	for(int i=0;i<n;i++) cin >> name[i+1];

	int a,b;
	for(int i=0;i<n-1;i++) {
		cin >> a >> b;
		if (a>b) swap(a,b);
		graph[a].pb(b);
		if (a!=1) graph[b].pb(a);
	}

	dfs(1);



	// show tree
	// for(int i=1;i<=n;i++) {
	// 	cout << i << "-> ";
	// 	for(auto child: tree[i]) {
	// 		cout << child << " " ;
	// 	}
	// 	cout << endl;
	// }
	
	int root;
	char qr[26];
	while (q--) {
		cin >> root >> qr;
		// cout << root << " " << qr << endl;
		int count = 0;

		for(int i=0;i<strlen(qr);i++) {
			if (tree[root][qr[i]-91]) count++;
		}
		cout << strlen(qr) - count << endl;
	}

}
