#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define int64 long long int
#define vint vector<int>
#define vint64 vector<int64>
#define forf(i,n) for(int i=0;i<(int)(n);i++)
#define fore(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define forb(i,n) for(int i=(int)(n-1);i>=0;i--)
char vowel[] = {'A','a','E','e','I','i','O','o','U','u','Y','y'};

bool in(char& c){
	forf(i,strlen(vowel)) 
		if (c==vowel[i]) return true;
	return false;  	
}
int main()
{
	char str[100]; cin>>str;
	forf(i,strlen(str)) {    
		if (in(str[i])) continue;
		else {
			if (str[i]>='A' && str[i]<='Z') str[i] += 'a'-'A';
			cout<<"."<<str[i];  
		}
	}	
	return 0;
}
