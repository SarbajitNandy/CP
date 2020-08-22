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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// freopen("in.txt", "r", stdin);

	int n; cin >> n;
	
	char stack[200000];

	string str;

	cin >> str ;

	int top = -1;

	for(auto i: str) {
		if (i==')') {
			if (top==-1) {
				stack[++top] = i;
			} else {
				if ( stack[top] == '(') { top--;}
				else { break; }
			}
		} else {
			stack[++top] = i;
		}	
	}

	// cout << "top "<< top+1 << endl;

	if (top+1==0) { cout << "Yes" << endl;}
	else {
		if (top+1 == 2) {
			if ( stack[0] == ')' && stack[1]=='(') { cout << "Yes\n";}
			else { cout << "No" << endl; }
		} else {
			cout << "No" << endl;
		}
	}

	return 0;
}
