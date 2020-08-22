#include <bits/stdc++.h>
using namespace std;      
// #define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_bacK(x)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

const int M = 1e5+1;
//bool arr[M];  // 1_-> odd , 0-> even;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("in.txt", "r", stdin);
    
    int t; cin >> t;
    int n,q, val;
    int odd, even;
    while (t--)
    {
        odd=even=0;
        cin >> n >> q;
        
        for(int i=0;i<n;i++) {
            cin >> val;
            if (__builtin_popcount(val) & 1) {
                    odd++;
            } else even++;
        }
        //cout << "input" << endl;
        while (q--) {
            cin >> val;
            if (__builtin_popcount(val)&1) {
                cout << odd << " " << even << endl;
            } else cout << even << " " << odd << endl;
        }
        
    }
    



}
