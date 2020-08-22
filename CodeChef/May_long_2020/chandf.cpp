#include <iostream>
using namespace std;
long x,y,l,r;

bool inRange(long n) {
    return (n<=r && n>=l);
}
int main() {

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t; cin >> t ;
	
	while (t--) {
	    cin >> x >> y >> l >> r;
	    long xy = x|y;
	    long gt = 2;
	    if (inRange(xy)) {
	        cout << xy << endl; continue;
	    }
	    if (l>xy) {
		    while (gt>xy) {
		        gt*=2;
		    }
		    gt+=xy;
		    if (inRange(gt)){
		        cout << gt << endl; continue;
		    }
		}


	  
	}
	return 0;
}
