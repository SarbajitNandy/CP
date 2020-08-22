#include <bits/stdc++.h>
using namespace std;        
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

// Finding out the longest common subsequence between two strings

int arr[51][51],m,n;
char a[50],b[50];

int main()
{
	freopen("in.txt","r", stdin);
	cin>>a>>b;
	cout<<a<<b<<endl;
    n = strlen(a); m = strlen(b);
	cout<<m<<n;
	forf(i,n){
		forf(j,m){
			if (a[i]==b[j]) { arr[i][j] = 1 + arr[i-1][j-1]; }
			else {
				arr[i][j] = max(arr[i-1][j], arr[i][j-1]); 
			}
		}
	}    			
	cout<< "The dynamic array is:  " <<endl;
	forf(i,n){
		forf(j,m) {
			cout<< arr[i][j] << " ";
		}
		cout<<endl;
	}
}
