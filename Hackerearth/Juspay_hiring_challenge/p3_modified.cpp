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
#define vx(x) vector<x>
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
set<int> rmNodes;
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
        return true;
 
    // marking the current node as visited
    visited[u] = 1;

    // for (int i = 0; i < n; i++) {
    //     if (graph[u][i] != -1 && !visited[i]) {
 
    //         // cost of the further path
    //         if (minimumCostSimplePath(i,destination, visited, graph)) { 
    //             debug(u);
    //             rmNodes.insert(u) ; return true; }
    //     }
    // }
    int multi = 0;
    vector<int> stageNodes;
    debug(u);
    for(auto each : graph[u]) {
        if (!visited[each.ff]) {
            int res = minimumCostSimplePath(each.ff,destination, visited, graph);
            if (res) { debug(each.ff); debug(res); multi=multi==0 ? 1 : 2; if (res==1)stageNodes.pb(each.ff); rmNodes.insert(each.ff);}
        }
    }
    debug(rmNodes);

    if (multi==2) {
        for (auto each : stageNodes) rmNodes.erase(each);
        rmNodes.insert(u);
    }
    
    debug(rmNodes);

    visited[u] = 0;
 
    // returning the minimum cost
    return multi ;
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
    vector<pair<int,int>> graph[n];
    int m,v1,v2,value; cin >> m;
    for(int i=0;i<m;i++) {
        cin >> v1 >> v2 ;
        // cerr << nodeMap[v1] << ","<< nodeMap[v2] ;
        // No use of value 
        graph[nodeMap[v1]].pb(mk(nodeMap[v2],1));
    }

    // debug(graph);
    for(int i=0;i<n;i++) {
        for(pair<int,int> it: graph[i]) {
            cerr << "(" << it.ff << " ," << it.ss << "), " ;
        }
        cerr << endl;
    }
    int a,b; cin >> a >> b;
    int a1 = nodeMap[a];
    int b1 = nodeMap[b];
    // debug(a);
    // debug(b);

    bool vis[n]; memset(vis,0,sizeof vis);
    int ans;
    ans = minimumCostSimplePath(a1,b1,vis, graph);
    debug(ans);
    // cout << ans << endl;
    if (ans) {
        cout << "ans: \n" ;
    for(auto e : rmNodes) {
        int each = nodes[e];
        if (each!=b) cout << each << " ";
        }
    }
    cout << '\n';
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