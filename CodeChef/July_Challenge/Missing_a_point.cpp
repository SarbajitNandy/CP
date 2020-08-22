#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
#define LONG_INT_MAX 0x7fffffffffffffff

typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;


int get_odd(vi &x) {
    int j=0;
    forf(i, x.size()) {
        j=i;
        while(j<x.size() && x[i]==x[j]) {
            j++;
        }

        if ((j-i)&1) return x[i];
        i=j-1;
    }
    return -1;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin) ;
		freopen("out.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    int t; cin >> t;
    int n,m,v;

    vi x,y;

    while (t--) {
        cin >> n; m = 4*n -1;

        forf(i,m) {
            cin >> v; x.pb(v);
            cin >> v; y.pb(v);
        } 

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        cout << get_odd(x)<< " " << get_odd(y) << endl;

        x.clear(); y.clear();
    }
	

}
