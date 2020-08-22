#include <bits/stdc++.h>
using namespace std;      
#define endl '\n'
#define MAX 1e9+7  
#define pb(x) push_back(x)
#define mk(x) make_pair(x)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
#define LONG_INT_MAX 0x7fffffffffffffff

typedef long long int ll;
typedef vector<int> vint;
typedef vector<ll> vint64;

int main() {
    // int t; cin >> t;
    // ll n;
    // ll res; bool f = false;
    // while (t--) {
    //     res = 0;
    //     cin >> n;
    //     if (__builtin_popcount(n)==1) { cout << -1 << endl; continue; }
        
    //     // add odd
    //     res+= n/2;
        
    //     for (ll i=2;i<=n;i+=2) {
    //         if (__builtin_popcount(i)==1) {
    //             if (i+1<=n) res += i;
    //             else {  break; }
    //         } else {
    //             bitset<64> s = i;
    //             for(ll j=0;j<=n;j++) {
    //                 if (s[j]) {
    //                     res+=pow(2,j); break;
    //                 }
    //             }
    //         }
    //     }
        
    //     if (!f) cout << res << endl;
    //     else cout << -1 << endl;
        
    // }

    int t; cin >> t;
    int n; 
    while ( t--) {
        cin >> n;
        ll res = 0;
        res += n&1 ? n/2 : (n-1)/2;
        ll log_v = log2(n);
        ll div = 2;
        for(int i=1;i<=log_v;i++) {
            res += ((n-div)/(div*2))* div;
            if (div+1<=n) res+=div;
            else {res=-1; break;}
            cout << res << "  " << div << endl; 
            div*=2;
        }
        cout << res << endl;
    }
}