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
#define vi vector<int>
#define vl vector<ll>
#define vpl vector<pl>
#define vx(x) vector<x>
#define mk make_pair
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


bool compareV(pair<int,int> a, pair<int,int> b ) { return a.ss > b.ss;} 

void solve()
{
	int n,x,y; cin >> n >> x >> y;
	vector<pair<int,int>> contests;
	int v1,v2;
	for(int i=0;i<n;i++) { cin >> v1 >>v2; contests.pb(mk(v1,v2));}
	// sort based on v2
	// sort(contests.begin(), contests.end(), compareV);

	vi entryTime(x,0), exitTime(y,0);
	for(int i=0;i<x;i++) cin >> entryTime[i];
	for(int i=0;i<y;i++) cin >> exitTime[i];
	sort(entryTime.begin(),entryTime.end());	//debug(entryTime);
	sort(exitTime.begin(),exitTime.end());	//debug(exitTime);
	int mn=INF;
	for(pair<int,int> each : contests) {
		// int entry=-1, exit=-1;
		auto lt = upper_bound(entryTime.begin(), entryTime.end(), each.ff);
		auto rt = lower_bound(exitTime.begin(), exitTime.end(), each.ss);
		// debug(entry);debug(exit);
		if (lt!=entryTime.begin() && rt != exitTime.end()){ lt--; mn=min(mn, *rt-*lt+1);  }
	}

	cout << mn;


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