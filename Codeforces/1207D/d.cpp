#include <bits/stdc++.h>
using namespace std;
#define LL long long       
#define endl '\n'
#define MAX 1e9+7  
#define LPrime 998244353  
#define pb(x) push_bacK(x)
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

bool compare(pair<int,int> a , pair<int,int> b) {                            
	return (a.first < b.first ) || (a.first==b.first && a.second < b.second);
}
        
int main()
{                                                                            
	ios_base::sync_with_stdio(0); cin.tie(NULL);


                             
	map<int,int> forA, forB;

	int n; cin >> n;
	int a,b;
	pair<int , int > data[n];

	// calculation for factorial 
	int fact[n+1];
	fact[0]=fact[1]=1;
	fore(i,2,n) {
		fact[i] = (i * 1LL * fact[i-1]) % LPrime;		
	}

	// take input
	forf(i,n) {
		cin >> data[i].first >> data[i].second;
		forA[data[i].first]++; forB[data[i].second]++;			
	} 

	//sort(data, data+n);
	
	// print data after sorting 
	/*for(auto x: data) {
		cout << x.first << " " << x.second << endl;
	}*/
                                                      
    int ans = fact[n];   

    // after calculation for a
    int calA=1;
    for(auto x: forA) {                     
    	calA = (calA*1LL*fact[x.second])%LPrime;
    }

    //cout << calA << endl;
    ans =(ans+LPrime-calA)%LPrime;
       	
   	// aftert calculation of b 
   	int calB = 1;
   	for(auto x: forB) {
    	calB = (calB*1LL*fact[x.second])%LPrime;
    }

    //cout << calB << endl;
    ans =(ans+LPrime-calB)%LPrime;         //cout << calA << endl;
              
    sort( data, data+n); // sorting based on b
    /*
    cout << "printing  data" << endl;
    for(auto x: data) {
		cout << x.first << " " << x.second << endl;
	}*/
	// finding the intersection area
	int l = 0;
    int d = 1;
    while(l < n){
        int r = l + 1;
        while(r < n && data[l].first == data[r].first) ++r;
        map<int, int> m;                                    

        for(int i = l; i < r; ++i) ++m[data[i].second];
        for(auto p : m) d = (d*1LL*fact[p.second])%LPrime;
        l = r;
    }

    for(int i=1;i<n;i++) {
    	if (data[i-1].second > data[i].second) { d=0; break; }
    }

    ans = (ans+d)%LPrime;
    //cout << calA << " " << calB <<" "<< d <<endl;

    cout << ans << endl;

	return 0;

}
