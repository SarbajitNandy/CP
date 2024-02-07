#include <bits/stdc++.h>

using namespace std;
void explainPair() {
    pair<int,int> p = {1,2};
    pair<int,pair<int,string>> p2 = {1,{2, "Sarbajit"}};

    cout << p.first << " " <<p.second << endl;
    cout << p2.second.first << " " <<p2.second.second << endl;
}

void explainVector() {
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2); // Same as push back but faster

    vector<pair<int,int>> vec;

    vec.push_back({1,2});
    vec.emplace_back(1,2); // same as push back 

    vector<int> v2(5,100); // {100,100,100,100,100}
    vector<int> v3(5); // {G,G,G,G,G}

    vector<int> copyOfV2(v2); // copy the content of a vector

    vector<int>::iterator it = v2.begin();
    vector<int>::iterator rit = v2.end(); // rbegin rend is aslo avaiable

    cout << *it << endl;

    for(auto it2 : v2) {
        cout << it2 << endl;
    }


    // deletion 
    v.erase(v.begin()+1); // single item 
    v.erase(v.begin()+1, v.end()+3); // multiple element [start, end-1]

    // insertion 
    vector<int> v(2,100); // {100, 100}
    v.insert(v.begin(), 200); //  {200, 100,100}
    v.insert(v.begin()+1, 2, 300); // {200, 300, 300, 100 , 100}

    // size 
    v.size(); // size of a vector

    // pop
    v.pop_back(); // delete last item 
    
    // swap 
    // have v1, v2
    v.swap(v2);

    v.clear(); // erase entire vector

    cout << v.empty() << endl; // check if a vector is empty




}

int main()
{
    // container
    // explainPair();
    explainVector();
}