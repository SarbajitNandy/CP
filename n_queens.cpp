#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_back(x)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

int n;
vector<int> q_pos;

int is_valid_pos(int k, int pos) {
	// k => queen no
	for(int i=0;i<q_pos.size();i++) {
		if (q_pos[i]==pos || abs(i-k)==abs(q_pos[i]-pos)) return false;
	}
	// cout << "find\n";
	return true;
}

void n_queen(int k) {
	if (k==n) {
		for(auto item : q_pos) cout << item << " ";
		cout << endl;
	} else {
		forf(i,n) {
			if (is_valid_pos(k,i)) {
				// cout << i << " is valid for " << k << endl;
				q_pos.pb(i);
				n_queen(k+1);
				q_pos.pop_back();
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	
	n=8;
	n_queen(0);

}
