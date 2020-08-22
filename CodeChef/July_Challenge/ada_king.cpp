#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n);i>=0;i--)
#define LONG_INT_MAX 0x7fffffffffffffff

typedef long long int ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;


char arr[8][8];

void init() {

    forf(i,8) {
        forf(j,8) arr[i][j]='.';
    }
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

    while (t--) {
        int n; cin >> n;
        init();

        float mb = sqrt(n);
        int uB = (ceil(mb)==(int)mb) ? ceil(mb) : ceil(mb);
        int upB = pow(uB,2);
        int remB = upB-n;
        
        arr[0][0]='O';
        
        // cout << uB << " " << remB << endl;
        if (uB<=7)
        forf(i,uB+1) {
            arr[i][uB]=arr[uB][i]='X';
        }
        forf(i, uB) {
            if (remB) {
                if (remB >=2) {
                    arr[i][uB-1]=arr[uB-1][i]='X'; remB-=2;
                } else {
                    arr[i][uB-1]='X'; remB--;
                }
            } else break;
        }
        
        cout << n  << endl;
        forf(i,8) {
            forf(j,8) cout << arr[i][j];
            cout << endl;
        }

    }
}
