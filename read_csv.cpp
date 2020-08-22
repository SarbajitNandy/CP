// #include <bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>


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
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin) ;
		freopen("out.txt", "w", stdout) ;
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;

    string file = "test.csv";

    ifstream fileStream(file);
    string parseRow, parseCol;

    vector<vector<string>> data;
    vector<string> col;
    while (getline(fileStream, parseRow, '\n')) {
        stringstream rowStream(parseRow);
        
        while (getline(rowStream, parseCol, ',')) {
            col.pb(parseCol);
        }

        data.pb(col);

        col.clear();

    }

    // printing data;

    for( auto row : data) {
        for (string col: row) cout << col << " ";
        cout << endl;
    }

    cout << "size " << endl;
    cout << data.size() << " " << data[0].size() << endl;
	

}
