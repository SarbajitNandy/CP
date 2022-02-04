#include <bits/stdc++.h>
using namespace std;

void go(string& s, int start) {
    if (start==s.size()-1 || start==1 ) {
        cout << s << endl; return;
    }
    int i=start;
    while(i<s.size()) {
        swap(s[start], s[i]);
        go(s,start+1);
        swap(s[start], s[i]);
        i++;
    }
}

int main() {
    freopen("in.txt","r", stdin);
    freopen("out.txt","w", stdout);

    string s="ABCD";
    go(s,0);

}


/*

ABCD
BACD
CBAD
DBCA



*/