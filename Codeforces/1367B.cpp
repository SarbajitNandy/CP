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


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	int t; cin >> t;
    int n;
    int arr[40];
    int w_0, w_1;
    while (t--) {
        cin >> n;
        w_0=w_1=0;

        forf(i,n) {
            cin >> arr[i];
    // cout << arr[i] << " " << i << endl;
            if (arr[i]%2 != i%2) { 
                if (i&1) w_1++;
                else w_0++;
                // cout << w_0 << " " << w_1  << endl;
            }
            
        }
        if (w_1 ==w_0) cout << w_1 << endl;
        else cout << -1 << endl;
    }

}
