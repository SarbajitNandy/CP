#include <bits/stdc++.h>
using namespace std;        
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

char sh[] = {"ACTG"};
int compare(char *a) {
	int s=0,f;
	forf(i,4) {
		f = abs(*(a+i) - sh[i]);
		//cout << a[i]<< " ";
		//cout << "f: "<<f<<endl;
		if (f > 13) {
			s += 26 - f;
		} else { s += f;}
	}
	//cout << s<<endl;
	return s;
}

int main()
{
	int n,s=0,j=0,tmin= 999; cin >> n;
	char arr[n];

	forf(i,n) {
		cin >> arr[i];
		if (i>=3) {
			s = compare(arr+j);
			if (s < tmin) { tmin=s;}
			j++;
		}
	}
	cout << tmin <<endl;
}
