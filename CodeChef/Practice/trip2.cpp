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

int arr[100001], n ,k;

bool solve(int left, int right) {
	int k1 = 1,i=0;
	while ( left <= right) {
		i++;
		//cout << "try: " << left << " " << k1 << endl;
		if ( (left==0 && arr[left+1]!=k1) || (left+1==n && arr[left-1]!=k1)) { arr[left]=k1; left++; i=0; }
		else if ( k1 != arr[left-1] && k1!=arr[left+1] ) { /*cout << left << " " << k1 << endl; */arr[left]=k1; left++; i=0;}
		k1 = (k1%k) + 1;	
	}	
	return true;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	int t; cin >> t;

	int cnt, solved_upto, terminate;
	bool is_solved ;
	while (t--) {
		is_solved = true; cnt = 0; solved_upto = -1 ; terminate = 0;
		cin >> n >> k;

		forf(i,n) cin >> arr[i];

		if (k==2) {
			//int even =2; odd=1;
			int last=-1;
			forf(i,n) if (arr[i]!=-1) { last=i; break; }
			if (last==-1) {
				 int k1=1;
				 forf(i,n) { arr[i]=k1; k1=k1%k +1;}
			}
			else if (arr[last] == 1 ) {
				int k1=2;
				fore(j,last+1,n-1) {
					if (arr[j]==-1) { arr[j] = k1; }
					else if (arr[j]!=k1){ is_solved = false; break; }
					k1=k1%k +1; 
				}
				k1 =  2;
				forb(j,last) {
					arr[j] = k1; k1=k1%k +1;
					//else if (arr[j]!=k1){ is_solved = false; break; }
				}
			}
			else {
				int k1=1;
				fore(j,last+1,n-1) {
					if (arr[j]==-1) { arr[j] = k1; }
					else if (arr[j]!=k1){ is_solved = false; break; }
					k1=k1%k +1; 
				}
				k1 =  1;
				forb(j,last) {
					arr[j] = k1; k1=k1%k +1;
					//else if (arr[j]!=k1){ is_solved = false; break; }
				}
			}	
		} else {
		forf(i,n) {
			if (arr[i] == -1 ) {
				cnt++; // no of spaces to be filled
				if (i==n-1) { 
				 	if (!solve(solved_upto+1, n-1) ) { is_solved = false;}				 	
				}            
			} else {
				if (cnt) {  
					//if (k - terminate < count) { cout <<"NO" << endl;}  // flaw idea, not gonna happen 
					//cout << solved_upto << endl;
					solve(solved_upto+1, i-1);
					solved_upto = i;										
				} else {
					//if ( i!=0 && arr[i-1] == arr[i] ) { is_solved = false; break; }
					solved_upto = i;
				}
			
				cnt=0;
			}
		} }

		if (is_solved) {  
			cout << "YES" << endl;
			for(int i=0;i<n;i++) { cout << arr[i] << " ";} cout << endl;
		} else {
			cout << "NO" <<  endl;
		}
		
	}	                                                                                                                         
}
