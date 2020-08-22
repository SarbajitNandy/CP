#include <bits/stdc++.h>
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
	freopen("in.txt","r", stdin);
	char arr[35], c,q;
	cin >> arr >> q;
	int l= strlen(arr), start=0.n;
	char first[q];
	int i=0
	while (i<q){
		cin >> n>>c;
		if (c=='L') {
			start += (n%l);
		} else {
			start -= (n%l);
		}

			first[i] = arr[start];
			i++;
	}


}
