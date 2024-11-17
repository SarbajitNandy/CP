#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();

        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> inDegree;
        queue<char> qu;
        
        for(int i=0;i<n;i++) {
            for(const char& c : words[i]) {
                inDegree[c]=0;
            }
        }
        
        for(int i=1;i<n;i++) {
            const string& s1 = words[i-1];
            const string& s2 = words[i];
            int mn = min(s1.length(), s2.length());
            if (s1.size() > s2.size() && 
                s1.substr(0, mn) == s2.substr(0, mn)) {
                return "";
            }
            for(int j=0;j<mn;j++) {
                if (s1[j]!=s2[j]) {
                    inDegree[s2[j]]++;
                    adj[s1[j]].push_back(s2[j]);
                    break;
                }
            }
        }
        
        for(auto u : inDegree) {
            if (u.second==0) qu.push(u.first);
        }
        

        string res = "";
        while(!qu.empty()) {
            char u = qu.front(); qu.pop();
            res += u;
            
            for(const char& v : adj[u]) {
                inDegree[v]--;
                
                if (inDegree[v]==0) qu.push(v);
            }
        }
        return res.size()==inDegree.size() ? res : "" sda;
    }
};
