#include <bits/stdc++.h>
using namespace std;        
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

typedef struct node {
	int64 ar[5];
}Node;
bool compare(Node &x, Node &y){
	//cout<<x.ar[3] << " " << y.ar[3]<<endl;
	/*if (x.ar[0]==1 && y.ar[0]==2){
		return (x.ar[3]<0);
	} else if (x.ar[0]==2 && y.ar[0]==1) {
		return true;
	}else return true;
	*/                                          
	if (x.ar[4]<y.ar[4]) return true;
	else if (x.ar[4]==y.ar[4] && x.ar[3]<y.ar[3]) return true;
	else return false;
	
}
int main()
{
	freopen("in.txt","r",stdin);
	int n; int64 q; cin>>n>>q;
	int64 a[n];
	Node qu[q];
	forf(i,n) cin>>a[i];
	forf(i,q){
		forf(j,4) cin>>qu[i].ar[j];
		if (qu[i].ar[3]<0 && qu[i].ar[0]==1) qu[i].ar[4]=0;
		else if (qu[i].ar[3]<0 && qu[i].ar[0]==2) qu[i].ar[4]=1;
		else if (qu[i].ar[3]>=0 && qu[i].ar[0]==2) qu[i].ar[4]=2;
		else if (qu[i].ar[3]>=0 && qu[i].ar[0]==1) qu[i].ar[4]=3;
	}
	//vector<Node> vec (qu,qu+q);		
	sort(qu,qu+q,compare);
	forf(i,q){
		cout<<qu[i].ar[0]<<" "<<qu[i].ar[1]<<" "<<qu[i].ar[2]<<" "<<qu[i].ar[3]<<" "<<qu[i].ar[4]<<endl;
		if (qu[i].ar[0]==1){
			fore(j,qu[i].ar[1],qu[i].ar[2]){
				a[j-1] += qu[i].ar[3];
			}
		}
		else {
			fore(j,qu[i].ar[1],qu[i].ar[2]){
				a[j-1] = qu[i].ar[3];
			}
		}
	}
	forf(i,n) cout<<a[i]<< " "; 
	return 0;
}
