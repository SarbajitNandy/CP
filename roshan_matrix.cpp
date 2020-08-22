#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
// #define fore(i,a,b,inc) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=inc:i+=inc)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
#define LONG_INT_MAX 0x7fffffffffffffff

typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;

int res[1001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

    int n,m ; cin >> n >> m;
    char ch;
    bool arr[n][m];
    forf(i,n){
        forf(j,m) {
            cin >> ch;
            if (ch=='*') { arr[i][j]=1; res[1]+=1; }
            else arr[i][j]=0;
        }
    }

    // forf(i,n){
    //     forf(j,m) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    int k_len; cin >> k_len;
    vi k_v;
    int v,mx; 
    forf(i,k_len) { 
        cin >> v; 
        if (v>mx) mx = v;
        k_v.pb(v);
    }
    mx = min(mx, min(n,m));

    fore(k,2,mx) {
        // cout << k << "k" << endl;
        forf(i,n-k+1) {
            forf(j,m-k+1) {
                if (arr[i][j] && arr[i][j+1] && arr[i+1][j+1] && arr[i+1][j])
                    res[k]+=1;
                else arr[i][j]=0;
            }
        }
        res[k]+=res[k-1];
    }

    for(auto k : k_v) {
        if (k>=mx) cout << res[mx] << endl;
        else cout << res[k] << endl;
    }



	

}
