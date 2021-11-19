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
#define MOD 1000000007
#define ull unsigned long long
#define ll long long
#define ld long double
#define pl pair<ll, ll>
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

void solve()
{

    string a,b;
    cin >> a >> b;
    debug(a);debug(b);

    int n,m; n=a.length();m=b.length();
    debug(n);debug(m);
    int dp[n+1][m+1]; 
    for(int i=0;i<n+1;i++)dp[i][0]=0;
    for(int i=0;i<m+1;i++)dp[0][i]=0;

    for(int i=1;i<n+1;i++) {
        for(int j=1;j<m+1;j++) {
            // debug(a[i-1]);debug(b[j-1]);
            if (a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }

    for(int i=0;i<n+1;i++) {
        for(int j=0;j<m+1;j++) cerr << dp[i][j] << " ";
        cerr << endl;
    }

    // debug(dp);
    cout << "MAX Length: " << dp[n][m] << endl;
    cerr << "MAX Length: " << dp[n][m] << endl;


    int i=n,j=m;
    string ans="";

    while (dp[i][j]>0) {
            int in=i,jn=j,mx=-1;
        // debug(a[i-1]);debug(b[j-1]);
        if (i>=1 && j>=1 && a[i-1]==b[j-1]) {
            ans=a[i-1]+ans; debug(ans);
            i=i-1;j=j-1;
        }
        else {
            if (mx<dp[i-1][j]) {in=i-1;jn=j;mx=dp[i-1][j];}
            if (mx<dp[i][j-1]) {in=i;jn=j-1;mx=dp[i][j-1];}
            if (mx<dp[i-1][j-1]) {in=i-1;jn=j-1;mx=dp[i-1][j-1];}
            i=in;j=jn;
        }
        

    }

    cout << "Sequence: " << ans;
    cerr << "Sequence: " << ans;

    	 
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
  
    cerr << "\ntime taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
// `Keep It Simple Stupid!