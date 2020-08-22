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
	freopen("in.txt", "r", stdin);
	int t; cin >> t;

	string str; int len;
	int posA, posB;
	int vA,vB; 
	int step;
	int rA, rB;

	while (t--) {
	 posA = posB = 0;
	 cin >> str; 

	 cin >> vA >>vB ;
	 
	 for(int i=0;str[i] != '\0';i++) {
	     if (str[i] == 'A') { posA = i+1;  }
	     else if ( str[i] == 'B') { posB = i+1; } 
	     else { continue ; } 
	 }
	 
	 cout << posA << " " << posB << endl; 

	 step =( posB - posA  + 1) / (vA+ vB); cout << "step : "<< step << endl;

	 rA = posA + (vA * step);
	 rB = posB - (vB * step);		// let them cross

	 cout << rA << " " << rB << endl;

	 if ( rA == rB) cout << "unsafe"<< endl;
	 else cout << "safe" << endl;

	 
	 
	}

}
