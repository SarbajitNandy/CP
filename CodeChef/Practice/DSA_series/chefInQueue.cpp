#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;


ll MOD = 1000000007;
ll go(map<ll, vector<ll>> &cont, ll key, ll idx) {
    ll res=1;
    for(auto each : cont ) {
        // cout << "key -> " << each.first << " Len of value " << each.second.size() << endl;
    	// for(auto v : each.second ) cout << v << " ";
        // cout << endl; 
        if (each.first > key && each.second.size()>0) {
    		for(auto v : each.second) {
                res *= (v-idx+1)%MOD;
    			res%=MOD;
            }
            cont.at(each.first).clear();
    	}
    }

    return res;
}

int main() {

    ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	// your code goes here
	ll n,k;
	cin >> n >> k;
	
	map<ll, vector<ll>> cont;
	ll each,res=1;
	for(ll i=0;i<n;i++) {
	    cin >> each;
	    // cout << "input " << each <<endl;
	    res*=go(cont, each, n-i)%MOD;
        res%=MOD;

	    if (each!=1){
	    	if (cont.count(each)) 
	    		cont.at(each).push_back(n-i);
	    	else {
	    		cont.insert(pair<ll, vector<ll>>(each,vector<ll>(1,n-i)));
	    		// vis[each]=1;
	    	}
	    }

        // for(auto each : cont ) {
        //     cout << "key -> " << each.first << " Len of value " << each.second.size() << endl;
        //     for(auto v : each.second ) cout << v << " ";
        
        // }
    
	    
	}

	cout << res << endl;
	
	return 0;
}
