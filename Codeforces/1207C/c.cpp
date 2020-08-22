#include <bits/stdc++.h>
using namespace std;        
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

int main()
{
	int t; cin >> t;
	int n;
	long long  ans,a,b;
	bool val;
	bool did_get=false;
	int start, end;
	vector<pair<int,int>> data;

	while (t--) {
		ans =0;
		start=end=0;
		cin >> n >>a >> b;
		data.clear();    

		getchar();
		forf(i, n) {
			char c = getchar();
			val = (c=='1')?1:0;
			//cout << val << endl;
			if (val) {
				if ( !did_get ) { did_get = true; start = i; if (!end) end=i; }
				else { end=i; }   			
			} else { did_get = false; if (start && end) { data.push_back({start,end}); start=end=0;} }
		}

		// solve
		/*
		ans = 8*a + 9*b;  cout << "ans " << ans << endl;
		// print data
		int p;
		if ( a<=b/2 || a==b ) { 
			for(auto x: data) {
				p = x.second - x.first + 2;
				ans += p*b + 2*a;
				cout << x.first << " " << x.second << endl;
			}
		} else {
			if (data.size() > 0) {
			auto it = data.begin(),itend = data.end();
			p = itend->second - it->first + 2;
			ans += p*b + 2*a;    }
		}   */
		start = end = 0;
		int k,p;
		ans = n*a + (n+1)*b;
     	for( auto x : data) {
     		//cout << x.first << " " << x.second << endl;
     		k =x.second - x.first + 2;
     		if (end == 0) {
     			ans += k*b + a;
     			end = x.second;
     		} else {
     			p = x.first - end - 2;
     			ans += min(2*a , p*b) + k*b;
     			end = x.second;
     		} 

     	} 
     	if (data.size()) { ans+=a; }
		cout << ans << endl;
	}
	

}