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
	freopen("out.txt", "w", stdout);

	int t; cin >> t;
	int st,it, ex;
	int diff, index,ans, len;
	bool sign;
	while (t--) {
		cin >>st >> it >> ex ; index=0; // cout << "t " << t << endl;

     	diff = st - it;

     	if (diff < 0 && abs(diff)==ex) ans = 0;
     	else if (diff >=ex) {
     		ans = diff ==ex ? ex : ex+1;
     	} 
     	else {

     		int len = (ex&1) ? (ex+1)/2 : ex/2+1;
     		sign = 0;
     		diff = -diff;

     		if (diff==0) ans = (ex&1) ? len : len-1;
     		else {
     			if (ex&1) {
     				diff = diff&1 ? (!sign)? diff+2 : diff : diff+1;
     				// if (!sign) diff+=2;
     				index = (diff-1)/2+1;
     			}
     			else {
     				diff = diff&1 ? diff+1 : (!sign)? diff+2 : diff;
     				// if (!sign) diff+=2;
     				index = (diff)/2+1;
     			}
     			ans = len - index +1;
     			//ans = (st > it && !(ex&1)) ? ans+1: ans;

     			if (ans < 0) ans=0;
     		}
     	}
     	cout << ans << endl;


        

	}
	return 0;

}
