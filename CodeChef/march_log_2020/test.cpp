#include <bits/stdc++.h>
using namespace std;


vector<int> graph[20];
vector<int> nodes;
int n;

ostream& operator<< (ostream& os, vector<int> v) {
    for(auto x: v) os << x << " ";
    return os;
}

int go(unsigned int root) {
    cout << root << endl;
    int m = 0;
    
    if (graph[root].size()==0) return nodes[root-1];
    for(auto x : graph[root]){
        m = max(m, go(x));
    }
    
    return  m+nodes[root-1];       
}

int main() {
    
    cin >> n;
    
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val; 
        nodes.push_back(val);
        //graph[i+1].push_back({});
    }
    int u,v;
    // enter the graph
    for (int i = 0; i < n-1; i++)
    {
        cin >> u >> v; graph[u].push_back(v);
    }
    
    
    
    //for(auto row: graph) cout << row << endl;
    
    cout << go(1);
    
    
    
    
}
