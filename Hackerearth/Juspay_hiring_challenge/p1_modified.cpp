/*
    Author : prashant_th18
                            :)
*/
// #pragma GCC optimize("O3")
// #pragma GCC target("popcnt")
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define INF INT_MAX
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pl pair<ll, ll>
#define mk make_pair
#define vl vector<ll>
#define vpl vector<pl>
#define pb push_back
#define all(v) begin(v), end(v)
#define PI 3.1415926535897932384626
#define fl(i, si, ei) for(ll i = si; i < ei; ++i)
#define nline '\n'
#define space ' '
#define ff first
#define ss second
#define sz(v) ((ll)(v).size())
#define set_bits __builtin_popcountll
#ifndef ONLINE_JUDGE 
#define debug(x) cerr << #x << " : "; _print(x); cerr << nline;
#else
#define debug(x)
#endif

int n;
// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered Set */ 
// #define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> /* Ordered MultiSet */ 
template <typename T> void _print(vector <T> v) { cerr << "[ "; for(auto myval : v) cerr << myval << " "; cerr << "]"; }
template <typename T1, typename T2> void _print(vector <T1, T2> v) { cerr << "[ "; for(auto myval : v) cerr << myval.ff << space << myval.ss << " "; cerr << "]"; }
template <typename T> void _print(set <T> v) { cerr << "[ "; for(auto myval : v) cerr << myval << " "; cerr << "]"; }
template <typename T1, typename T2> void _print(map<T1, T2> v) { cerr << "[ "; for(auto myval : v) cerr << myval.ff << space << myval.ss << " "; cerr << "]"; }
void _print(int a) {cerr << a;}
void _print(ll a) {cerr << a;}
void _print(ull a) {cerr << a;}
void _print(char a) {cerr << a;}
void _print(string a) {cerr << a;}
void _print(double a) {cerr << a;}

int minimumCostSimplePath(int u, int destination,bool visited[], vector<pair<int,int>> *graph)
{

    if (u == destination)
        return 0;
 
    visited[u] = 1;
 
    int ans = INF;
 

 	for(auto each : graph[u]) {
 		if (!visited[each.ff]) {
 			// cost of the further path
            int curr = minimumCostSimplePath(each.ff,
                        destination, visited, graph);
 			
            // check if we have reached the destination
            if (curr < INF) {
 
                // Taking the minimum cost path
                ans = min(ans, each.ss + curr); 
	 		}
	 	}
	 }
    visited[u] = 0;
 
    return ans;
}

void solve()
{

    cin >> n;
    int nodes[n];
    map<int,int> nodeMap;
    for(int i=0;i<n;i++) {
        cin >> nodes[i];
        nodeMap.insert(pair<int,int>(nodes[i],i));
    }

    // Graph Representation
    /*
		0 => [(1,3), (3,1)],
		1 => []
    */
    vector<pair<int,int>> graph[n];
    int m,v1,v2,value; cin >> m;
    for(int i=0;i<m;i++) {
        cin >> v1 >> v2 >> value;
        graph[nodeMap[v1]].pb(mk(nodeMap[v2],value));
    }

    // debug(graph);
    for(int i=0;i<n;i++) {
    	for(pair<int,int> it: graph[i]) {
    		cerr << "(" << it.ff << " ," << it.ss << "), " ;
    	}
    	cerr << endl;
    }


    int a,b; cin >> a >> b;
    a = nodeMap[a];
    b = nodeMap[b];
    debug(a);
    debug(b);

    bool vis[n]; memset(vis,0,sizeof vis);
    int ans;
    ans = minimumCostSimplePath(a,b,vis, graph);
    // debug(ans);
    cout << ans << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    cout << fixed << setprecision(0);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
        cout << nline;
    }
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
// `Keep It Simple Stupid!