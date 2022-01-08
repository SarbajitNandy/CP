#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("out.txt","w", stdout);
    vector<int> a1 = {1,2,3,4,5,6};

    vector<int> a2(a1.begin()+2, a1.end());
    // vector<int> a2(a1.rbegin(), a1.rbegin()+4);

    // a2.reserve();

    for(int e : a2) cout << e << " " ;

}