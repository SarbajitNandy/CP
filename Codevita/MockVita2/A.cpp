#include <bits/stdc++.h>
using namespace std;        
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;
#define MAX 1000000007

int main()
{
	int64 fact[28] = {1};
	forf(i,28){
		if (i) { fact[i] = (fact[i-1]*i)%MAX;}
	}

	int data[3][3];
	memset(data, 0, sizeof(data));
	forf(i,3) {
			cin >> data[0][i] >> data[1][i];
	}		

	char c;
	int single = -1;
	forf(i,3) 
		cout << data[2][i]<< endl;
		
	forf(i,3) {
		cin >> c;
		forf(j,3) {
			if (!j && (c-'A'+1)<=data[0][j]) { 
				if ( i==2) { single = j+1; break;}
				data[2][j]++; break;}
			else if ((c-'A'+1)<=(data[0][j]+data[0][j-1])) { 
				if ( i==2) { single = j+1; break;}
				data[2][j]++; break; }
		}
	}
	


	forf(i,3) 
		cout << data[2][i]<< endl;
	// Calculation for total and AD
	int t=1,ad=1;
	forf(i,3){
		cout << fact[data[1][i]] << endl;
		int n = data[0][i], r = data[1][i],m = data[2][i];
		t *= fact[n] / (fact[r] * fact[n-r]);
		ad *= fact[n-m] / (fact[r-m] * fact[n-r]);
	} 
	cout << "Total "<< t << "AD " << ad  << endl;

	// calculation for G
	forf(i,3) {

	}





}
