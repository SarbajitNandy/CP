class Solution {
private:
    vector<int> topoSort(int n, unordered_map<int,int> inDegree, unordered_map<int, vector<int>> adj) {
        queue<int> q;
        vector<int> res;

        for(auto e: inDegree ) {
            if (e.second==0) {
                q.push(e.first);
            }
        }

        while(!q.empty()) {
            int top = q.front(); q.pop();
            // cout << (char)(top+ 97) << endl;
            res.push_back(top);

            for(int v : adj[top]) {
                inDegree[v]--;

                if (inDegree[v]==0) {
                    q.push(v);
                }
            }
        }

        return res;
    }

public:
    string alienOrder(vector<string>& words) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> chars;

        int n = words.size();

        for(string s : words) {
            for(char e : s) {
                chars[e-97]=0;
            }
        }

        int V = chars.size();

        for(int i=1;i<n;i++) {
            string first = words[i-1];
            string second = words[i];

            int minLength = min(first.length(), second.length());
            int j=0;
            for(;j<minLength;j++) {
                if (first[j]!=second[j]) {
                    chars[second[j]-97]++;
                    adj[first[j]-97].push_back(second[j]-97);
                    break;
                }
            }

            if (j==minLength && first.length()>minLength) return "";
        }

        auto res = topoSort(V, chars, adj);

        if (res.size() != V) return "";

        string ans = "";
        for(int e : res) {
            ans += (char)(e + 97);
        }

        return ans;

        
    }
};