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
		int rows,cols,cnt;
		int arr[100][100], dp[100][100];
		map<int,int> line;
		// Data is filled succesfully
		cin>>rows>>cols;
		forf(i,rows){
			forf(j,cols){
				cin>>arr[i][j];
			}
		}

		// Calculation 

		memset(dp,0,sizeof(dp));
		cnt = 0;

		forf(j,cols){		// first row
			if (arr[0][j]==1){
				if (j==0) {
					dp[0][j] = arr[0][j];cnt++;
					line[cnt] = 1;
				}
				else if (j-1>=0) {
					if (dp[0][j-1]==0) { dp[0][j]=++cnt; line[cnt]++;}
					else { dp[0][j] = dp[0][j-1]; line[dp[0][j-1]]++;}
				}
				cout<<"row:"<< j<<" "<<cnt<<endl;
			}
		}

		forf(i,rows){		// first column
			if (arr[i][0]==1){
				if (i==0) { continue; }
				else if (i-1>=0) {
					if (dp[i-1][0]==0) {
						dp[i][0]=++cnt;
						line[cnt]++;
					}
					else { dp[i][0] = dp[i-1][0]; line[dp[i-1][0]]++;}
				} 
			}
		}

		fore(i,1,rows){		//Entire middle
			fore(j,1,cols){
				int &point = dp[i][j], &post = dp[i][j-1], &pre = dp[i-1][j];
				if (arr[i][j]==1){
					//cout<<"pre = "<<pre<< " post="<<post<<endl;
					if (post==0 && pre==0) { point = ++cnt; line[cnt]++; }
					else if (pre*post == 0) { 
						if (pre!=0) {
							point = pre; line[pre]++;
						} else { point = post; line[post]++;}
					}
					else if (pre!=post) { 
						if (pre<post) {
							line[pre] += (1 + line[post]);
							line.erase(post);
							point = post = pre; 							
						} else {
							line[post] += (1 + line[pre]);
							line.erase(pre);
							point = pre = post;
						}
						if (dp[i-1][j-1]==0) {cnt--;}
					}
					else {		// 
						point=pre; line[pre]++;
					}
				}
			}
		}

		// Printing dp
		cout<< "DP array\n";
		forf(i,rows){
			forf(j,cols){
				cout<< dp[i][j]<< " ";
			}
			cout<<endl;
		}

		cout<< "result is: "<<cnt;
		cout<< "line array is: \n[ ";
		for(auto it = line.begin(); it!=line.end();it++){
			cout<< it->second<<" ";
		}
		cout<<"]";
		return 0;
}
	