#include <bits/stdc++.h>
using namespace std;        
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

int gates[3][2], cage[2], mgate = -1;

float cageDist(int x,int y){
	return sqrt((x-cage[0])*(x-cage[0])+(y-cage[1])*(y-cage[1]));
}

float minGate(int x,int y) {
	float m=9999, d=0;
	for(int i=0;i<3;i++) {
		d = sqrt((x-gates[i][0])*(x-gates[i][0])+(y-gates[i][1])*(y-gates[i][1]));
		if (d<m) { m=d; mgate=i;}
	}
	return m;
}

int main()
{
	freopen("in.txt","r", stdin);
	int r,c; cin >>r>>c;
	for(int i=0;i<3;i++) {
		cin>> gates[i][0] >> gates[i][1];
	}
	cin >> cage[0] >> cage[1];
	int area = r*c, p=0;
	int  gland[area][2]; char q;
	int safe = 0;

	float gatedist[3];
	for(int i=0;i<3;i++) {
		gatedist[i] = sqrt((cage[0]-gates[i][0])*(cage[0]-gates[i][0])+(cage[1]-gates[i][1])*(cage[1]-gates[i][1]));
	}

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin >> q;
			if (q=='G'){
				gland[p][0]=i+1; gland[p++][1]=j+1;
				if (minGate(i+1,j+1)<gatedist[mgate]) { safe++; 
				}
				cout << i+1<< " " << j+1<< " "<<gatedist[mgate] << " "<< minGate(i+1,j+1)<<endl;
			}
			q=0;
		}
	}

	cout << endl<< safe;
}
