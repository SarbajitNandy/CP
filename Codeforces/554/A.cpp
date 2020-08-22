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
	freopen("in.txt", "r", stdin);
	int n,m,res=0; cin >>n>>m;
	int val, even_a, odd_a, even_b, odd_b;
	even_b=even_a=odd_b=odd_a=0;
	forf(i,n) { cin >>val;
		if (val%2==0) { even_a++; }
		else { odd_a++;}
	}
	forf(i,m) { cin >>val;
		if (val%2==0) { even_b++; }
		else { odd_b++;} 
	}

	if (even_a >= odd_b) { res+=odd_b;}
	else { res+=even_a; }

	if (even_b >= odd_a) { res+=odd_a;}
	else { res+=even_b; }

	cout << res;

}
