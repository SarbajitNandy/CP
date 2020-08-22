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

const int N = 1e5+1;
int Graph[N][2];
int Color[N];
map<int,int> childColorCount[N];

void child_Parent(int child, int Parent) {
	for(auto color: childColorCount[child]) {
			childColorCount[Parent][color.first]=color.second;
	}
	childColorCount[Parent][Color[child]]+=1;
}

void dfs(int Node) {
	int child1 = Graph[Node][0];
	int child2 = Graph[Node][1];

	if (child1!=0) {
		dfs(child1);
		child_Parent(child1, Node);
	}
	
	if (child2!=0) {
		dfs(child2);

		child_Parent(child2, Node);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int n; cin >> n; 
	int u,v;
	for(int i=1;i<n;i++) {
		cin >> u >>v ;
		if (v==1) swap(u,v);
		if (Graph[u][0]==0) Graph[u][0]=v;
		else Graph[u][1]=v;
	}

	for(int i=1;i<=n;i++) {
		cin >> Color[i];
	}

	dfs(1);

	int q,node; cin >> q;

	while (--q) {
		cin >> node;
	}

	for(int i=1;i<=n;i++) {
		for( auto item: childColorCount[i]) cout << item.first << ":" << item.second << " ";
		cout << endl;	
	}






	

}
