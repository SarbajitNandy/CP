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

    const int N = 2 * 1e5  + 1;

    bool arr[N];
    int n,k,l;
    
    bool check(int index) {
        int left = index - k, right = index -1;

        while (left >=0 and left<=right ) {
            if (arr[left]==1) { l=left+k; return false;}
            left++;
        }

        left = index+1; right=index+k;

        while (left <n and left<=right) {
            if (arr[left]==1) { l=left+k; return false;}
            left++;
        }
        
        return true;
    }

    int main() {
        #ifndef ONLINE_JUDGE
            freopen("in.txt", "r", stdin) ;
            freopen("out.txt", "w", stdout) ;
        #endif
        ios_base::sync_with_stdio(false);
        cin.tie(NULL) ; cout.tie(NULL) ;


        int t; cin >> t;
        char val;
        int count;
        while (t--) {
            count = 0;
            cin >> n >> k;
            forf(i,n) {
                cin >> val;
                arr[i]= ((val=='1')?1:0);
            }

            for(int i=0;i<n;i++) {
                if (arr[i]==0) {
                    if (check(i)) { count++; i+=k;}    
                    else i=l;        
                }
                else i+=k;
            }
            cout << count << endl;
        }
    }