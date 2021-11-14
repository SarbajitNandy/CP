#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define pb(x) push_bacK(x)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;
const long MAX = 1e9+7;

int arr[50][50];
int n;

int go(int i, int j) {
	
	int a,b,c,d; a=b=c=d=0;
	int val = arr[i][j];
	arr[i][j] = -1 ;
	
	if (i!=n-1 ) { // go down
		int &x = arr[i+1][j];
		// cout << x << endl;
		if ( x==4) { return -1;}
		else if ( x==-1 || x==0) {a=0;}
		else a=go(i+1, j);
	} 
	if ( j!=n-1 ) {  // go right
		int &x = arr[i][j+1];
		// cout << x << endl;
		if ( x==4) { return -1;}
		else if (x ==-1 || x==0) { b=0; }
		else b=go(i, j+1);
	} 
	if ( j>=1 ) {  // go left
		int &x = arr[i][j-1];
		// cout << x << endl;
		if ( x==4) { return -1;}
		else if ( x ==-1 || x==0) { c=0;}
		else c=go(i, j-1);
	} 
	if ( i>=1 ) {  // go up
		int &x = arr[i-1][j];
		// cout << x << endl;
		if ( x==4) { return -1;}
		else if ( x ==-1 || x==0) { d=0; }
		else d=go(i-1, j);
	}
	
	// cout << "i:" << i << " j: "<< j ;
	// printf("#i:%d, j:%d >> a: %d, b:%d, c: %d, d: %d\n",i,j,a,b,c,d);
	
	if ( a==-1 || b==-1 || c==-1 || d==-1) return -1;
	else if ( a==2 || b==2 || c==2 || d==2 || val == 2) {
		if (a==3 || b==3 || c==3 || d==3 || val==3 ) return -1;
		else return 2;
	}
	else if ( a==3 || b==3 || c==3 || d==3 || val==3) {
		if (a==2 || b==2 || c==2 || d==2 || val == 2) return -1;
		else return 3;
	}
	else return 1;
	
}

bool checkISO(int i, int j) {
	if ((i!=0 && arr[i-1][j]!=0) || (j!=0 && arr[i][j-1]!=0) ||  (i!=n-1 && arr[i+1][j]!=0) ||  (j!=n && arr[i][j+1]!=0) ) return false;
	// if (j!=0 && arr[i][j-1]!=0) return false;
	// if (i!=n-1 && arr[i+1][j]!=0) return false;
	// if (j!=n && arr[i][j+1]!=0) return false;
	
	return true;
	
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	
	int t; cin >> t;
	bool turn = true;
	char ch;
	long res = 1;
	while (t--) {
		turn = true; res = 1;
		memset(arr, 0, sizeof(arr));
		cin >> n;
		forf(i,n) {
			forf(j,n) {
				cin >> ch;
				if ( ch == '.' ) arr[i][j] = 0;
				else if ( ch == '?')arr[i][j] = 1;
				else if ( ch == 'B')arr[i][j] = 2;
				else if ( ch=='P')arr[i][j] = 3;
				else arr[i][j] = 4;
			}
		}
		
		// cout << "out" << endl;
		
		// forf(i,n) 
		// {forf(j,n) cout << arr[i][j];
		// cout << endl;}
		
		forf(i,n) {
			forf(j,n) {
				int &x = arr[i][j];
				if ( x != 0 && x!=-1) {
					if (x == 4) {
						if (( i!=n-1 && arr[i+1][j] != 0 ) || ( j!=n-1 && arr[i][j+1]!=0)) { turn = false; break;}
					}
					else {
						if ( checkISO(i,j)) { 

							if ( x==1) {
								// cout << "ISO " << i << " " << j << endl;
								res *= 3; res = res % MAX;
							}							
						}
						else {
							// cout << "non\n";
							// cout << "non " << i << " " << j << endl;

							int l = go(i,j); //cout << l << endl;
							if (l==1) { res *= 2; res = res % MAX; }
							else if (l==-1) { turn = false; break;}
						}
					}
				} 
			}
		}
		// cout << "res " << endl;
		if (!turn) { cout << 0 << endl; }
		else { cout << res << endl;}
		
		// forf(i,n) 
		// {forf(j,n) cout << arr[i][j];
		// cout << endl;}
		
	}	
}
