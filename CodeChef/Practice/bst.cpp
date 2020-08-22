#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_back(x)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int LL;
typedef vector<int> vint;
typedef vector<LL> vint64;

/*       			Implementation on array
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);

	int n; cin >>n ;
	map<LL,int> arr;
	int val; char c;
	int numberOfvalues = 0;

	//memset(arr, 0, sizeof(arr));
	while (n--) {
		cin >> c >> val;

		if ( c=='i') {
			int root = 1;
			while (arr[root]!=0) {
				if ( arr[root] <= val) root = root*2 +1;
				else { root = root*2; }
			} 
			arr[root] = val;
			numberOfvalues++;
			//cout << "Insert " <<  root << "val: "<< val << endl;
			cout << root << endl;
		} else {
			int root=1;
			while (root <= pow(2,numberOfvalues)-1) {
				//cout << "Delete" <<root <<endl; 
				if (arr[root] == val) { 
					//cout <<"Delete " << root << "val: "<< val << endl;
					cout << root << endl;
					if (arr[root*2+1]!=0) {
						if (arr[root*2] != 0) {
							// find the min on right side
							int right = root*2+1;
							// move left until strick null
							while ( arr[right*2]!=0) { right *=2; }
							arr[root] = arr[right]; arr[right] = 0;
						} else {
							arr[root] = arr[root*2+1];	
						}
					} else { arr[root] = 0;  }
					break; 
				} else {
					if (arr[root]<val) {root=root*2+1; }
					else { root = root*2; }
				}
								
			}

			 	
		}
	}
	             

}   */

// Implementation with linked list

class Node {
	public:
		int val,pos;
		Node *left, *right;
		Node(int val ,int pos) {
			this->val = val; this->pos = pos;
			this->left = this->right = NULL;
		}
		void add(Node *child) {
			if (this->val < child->val) { this->right = child; child->pos = this->pos*2 +1; }
			else { this->left = child; child->pos = this->pos*2;   }
		}	
};

Node* findMin(Node *root) {
	Node *check=root, *pre=NULL;
	while (check->left!=NULL) { pre=check; check = check->left; }
	pre->left = NULL;
	//cout << check->val << endl;
	return check;
}

int main() {
	int n; cin >> n ;
	int val,root; char c;
	Node *head=NULL, *check=NULL, *pre=NULL;

	while (n--) {
		cin >> c >> val;
		check=pre=NULL;
		if (c=='i') {
			root = 1;
			if ( head ==NULL) { head = new Node(val, root); }
			else { 
				check = head;
				do {
					if ( check->val < val) {   
						pre = check; root = check->pos*2+1; check = check->right;                                                  // not completed
					} else {
						pre = check; root = check->pos*2; check = check->left;						
					}
				} while( check!=NULL);
				pre->add(new Node(val, root));
				check = pre = NULL;
//				cout << root << endl;
			}
			cout << root << endl;

		}else {
			// delete a node
			root=1;
			check=head; pre=NULL;
			bool rightOrLeft = 0;
			while (check!=NULL) {
				if (check->val == val) { break; }
				else {
					//pre=check;
					if (check->val < val) { pre=check; root=check->pos*2+1; check=check->right; rightOrLeft= 0;}
					else { pre=check; root=check->pos*2; check = check->left; rightOrLeft= 1;}
				}	
			}
			cout << root << endl;
			if ( check->left == NULL ) { if (rightOrLeft) { pre->left = check->right; } else { pre->right=check->right; } delete check;}
			else if ( check->right == NULL ) { if (rightOrLeft) { pre->left = check->left; } else { pre->right=check->left; } delete check;}
			else {
				Node *min = findMin(check->right); 
				check->val = min->val; delete min;
			}

		}		
	}
	return 0;
}

