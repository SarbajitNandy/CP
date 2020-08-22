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

vi A,B,N;
int n;


int prevA(int pos ) {
    int p=-1;
    for(int i=0;i<A.size();i++) {
        if (A[i]>pos) return p; 
        else p=A[i];
    }  
    return p;  
}


int prevB(int pos ) {
    int p=-1;
    for(int i=0;i<B.size();i++) {
        if (B[i]>pos) return p; 
        else p=B[i];
    } 
    return p;  

}

int nextA(int pos ) {
    for(int i=0;i<A.size();i++) {
        if (A[i]>pos) return A[i]; 
    } 
    return n+1 ;  

}

int nextB(int pos ) {
    for(int i=0;i<B.size();i++) {
        if (B[i]>pos) return B[i]; 
    }    
    return n+1;  
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin) ;
		freopen("out.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    char ch; cin >> n;
    
    int cA=0, cB=0;
    forf(i,n) {
        cin >> ch ;
        // cout << ch << endl;
        switch(ch) {
            case 'A': A.pb(i); break; 
            case 'B': B.pb(i); break; 
            case '-': N.pb(i); break; 
        }

    }

    // data 
    // for(auto i: A) cout << i << " "; 
    // cout << endl;
    // for(auto i: B) cout << i << " "; 
    // cout << endl;
    // for(auto i: N) cout << i << " "; 
    // cout << endl;



    for ( int pos : N) {
        auto leftA = prevA(pos);
        auto leftB = prevB(pos);

        auto rightA =  nextA(pos);
        auto rightB = nextB(pos);

        // cout << "left ->" << leftA << " " << leftB << endl;
        // cout << "right ->" << rightA << " " << rightB << endl;


        // work 
        if ( (leftA <= leftB) && (rightA <= rightB) ) {
            if (leftA==leftB && leftA==-1) {
                cA++;  //cout << "A" << pos << endl;
                continue;
            }
            if (rightA==rightB && rightA==15) {
                cB++; //cout << "B" << pos << endl; 
                continue;
            }
            
            int dis = (pos-leftB) - (rightA-pos);
            if (dis<0) {
                cB++; //cout << "B" << pos << endl;
            } else if (dis>0){
                cA++; //cout << "A" << pos << endl;
            }
        }    
    }

    // cout << cA << " " << cB << endl;

    // cout << ((cA+A.size() > cB + B.size()) ? 'A': 'B') << endl;

    if ((cA+A.size() > cB + B.size())) {
        cout << 'A' << endl;
    } else if (cA+A.size() < cB + B.size()){
        cout << 'B' << endl;
    } else cout <<  "Coalition government" << endl;


}
