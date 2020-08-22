#include <bits/stdc++.h>
using namespace std;   

#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);(a>=b)?i>=b:i<=b;(a>=b)?i-=1:i+=1)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)

typedef long long int int64;
typedef vector<int> vint;
typedef vector<int64> vint64;

// C++ STL tutorial

void print(vint p) {
	//cout<<&p<<endl;
	forf(i,p.size()) {
		cout<<p[i]<<" ";
	}
	cout<<endl;
}

int main()
{  
	//*****// Vectors

	vint  A = {10,5,2,6,3,7,8};
	sort(A.begin(), A.end());  // Sorting an array using buildin sort function  // here A.begin() returns the address of the begining of the array
	
	// // to sort these elements in descending order, use comparator function 

/*	forf(i,A.size()) {   		// A.size() returns the address of the array A
		cout<< A[i]<< " ";
	}		
*/
	bool check = binary_search(A.begin(), A.end(), 3);    // Binary search algorithm
	cout<< check<< endl;
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(123);	 // Now the array = 2,3,5,6,7,8,10,100,100,100,100,123

	vint::iterator it = lower_bound(A.begin(), A.end(), 99);     // Lower Bound means the first occurance of the number that is ">=" the searching number
	vint::iterator it2 = upper_bound(A.begin(), A.end(), 99);	  // Upper bound means the first occurance of the number that is ">" the searching number
	// rememer that both lower_bound and upper_bound returns the address of a memory location. By this, we can say that "it" and "it2" is a pointer.
	// On the above two lines, value of it = 100 and value of it2 = 123

	for(vint::iterator iter = A.begin(); iter!=A.end(); iter++) {	// It's a simple iterator used to iterate over the vector array
		cout<< *iter<< " ";
	}
	cout<<it2 - it<< endl;		// arithmatic operation are also possible in vector iterators

	// // One thing can also be done to avoid using vector iterator everytime
	for(auto x: A){		// "auto" is a new feature in C++ which helps to decide the proper form datatype automatically. 
		cout<<x<< " ";   // To edit the content of vector A, use reference of x instead of only x i.e "&x"
	}

	//*****// Set 

	cout<< "\nSet in C++\n";
	set<int> s;
	s.insert(1);     // Creating 4 elements in the set
	s.insert(2);
	s.insert(3);
	s.insert(-1);
	s.insert(4);
	for(auto x: s) {	// content of the set is always in ascending order
		cout<< x<< " ";
	} cout<<endl;

	//*// searching for a value if it exists in the set or not
	// find function 

	auto pre = s.find(5);		// find function returns the memory location of the searched item( if found ), otherwise returns end location of that set.
	cout << *pre <<endl;					// As find function returns a memory location, this must be a pointer.
	if (pre == s.end()) cout<< "Not present\n";		// this condition is checking what the searched value exists or not
	else { cout<< "present\n";}

	//*// upper_bound and lower_bound function 

	// these two functions work same like it does in case of vector but syntex is little bit different 
	auto s_it = s.lower_bound(2);   // In case of no match it will return the end memory location of the set 
	auto s_it2 = s.upper_bound(2);	

	cout<< *s_it2 <<" "<<*s_it << endl;

	//*****// map
	// For understanding the functionality of map, it's better to compare "map" with python dictionary .
	// the main concept here is to store values like a tuple of key-value pair <key,value>

	string st = "sarbajit";
	map<char,int> freq;

	for(auto c:st) { // Calculation of frequency
		freq[c]++;
	}

	// Printing the whole map structure

	for(auto it = freq.begin();it!=freq.end();it++) {
		cout<< "["<<it->first<<","<<it->second<<"]"<<endl;
	} cout<<endl;



	return 0;
}