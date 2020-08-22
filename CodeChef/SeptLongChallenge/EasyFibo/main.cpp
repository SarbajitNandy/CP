#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_bacK(x)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int LL;
typedef vector<int> vint;
typedef vector<LL> vint64;

int mat[2][2];
int ans[2][2];
int a,b,c,d;


void matrixExp(LL n) {
	mat[0][0] = mat[0][1]=mat[1][0]=1; mat[1][1]=0;
	ans[0][0] =1; ans[0][1]=0; ans[1][0]=0; ans[1][1]=1;
	int counter=0;
	while (n > 0) { counter++;
		if (n&1) {
			int a1,b1,c1,d1;
			a = mat[0][0];b=mat[0][1]; c=mat[1][0]; d=mat[1][1];
			a1 = ans[0][0];b1=ans[0][1]; c1=ans[1][0]; d1=ans[1][1];
			
			ans[0][0] = (a1*a + b1*c) %10;
			ans[0][1] = (a1*b + b1*d) %10;
			ans[1][0] = (c1*a + d1*c) %10;
			ans[1][1] = (c1*b + d1*d) %10;
		}

		n>>=1;
		a = mat[0][0];b=mat[0][1]; c=mat[1][0]; d=mat[1][1];
		mat[0][0] = (a*a + b*c) %10;
		mat[0][1] = (a*b + b*d) %10;
		mat[1][0] = (c*a + d*c) %10;
		mat[1][1] = (c*b + d*d) %10;

	}
	cout << "Counter " << counter << endl;
}


int nthFibo(LL n) {
	int a,b;
	a=0;b=1;

	if (n==1) return a;
	else if (n==2) return b;
	else {
		cout << "n " << n << endl;
		matrixExp(n-2);
		
		//cout << "3" << endl ; print() ; 
		// print();
		b = ans[0][0];
	}
	return b;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	freopen("out.txt", "w", stdout);

	int t; cin >>t ;
	LL n;

	while (t--) {
		cin >> n;
		cout << nthFibo(pow(2,(int)log2(n))) << endl;
		// cout << nthFibo(n) << endl;
	}

}
