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


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

    int t; cin >> t;

    while (t--) {
        char s[100]; cin >> s;

        if (strlen(s)>2) {
            for (int i = 0; i < strlen(s); i+=2)
            {
                cout << s[i];
            }
            cout << s[strlen(s)-1];
        } else {
            cout << s ;
        }
        cout << endl;
    }
}
