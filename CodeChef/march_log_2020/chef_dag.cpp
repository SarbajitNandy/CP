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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    map<int, int> dp;
    int t,n,q; cin >> t;
    const int null = 600;

    while (t--)
    {
        cin >> n >>q;
        int val;
        cin >> val;
        for (int i = 1; i < n; i++)
        {
            cin >> dp[val];
            val=dp[val];
        }
        dp[val]=null;
        
        for(auto x: dp) cout << x.first << " " << x.second << endl;
        
        
    }
    

}
