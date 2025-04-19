class Solution {
public:
    vector<int> freqCount(string word ) {
        vector<int> freq(26,0);

        for(char e : word) {
            freq[e-'a']++;
        }

        return freq;
    }

    bool diff(string& a, string& b) {
        int diff = 0;
        // for(int i=0;i<26;i++) {
        //     diff += abs(a[i]-b[i]);
        // }
        // // cout << diff << endl;
        // return diff;
        int size = a.size();

        for(int i=0;i<size;i++) {
            if (a[i]!=b[i]) diff++;
            if (diff>1) return false;
        }

        return diff == 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if(it==wordList.end()) return 0;

        int endIndex = it - wordList.begin() + 1;
        cout << endIndex << endl;
        int n = wordList.size() + 1;

        wordList.insert(wordList.begin(),beginWord);
        // wordList.push_back(endWord);

        // vector<vector<int>> freqList;
        // for(string e : wordList) {
        //     freqList.push_back(freqCount(e));
        // }

        vector<vector<int>> adj(n,vector<int>());

        for(int i =0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if (diff(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);

                    // cout<< i << " " << j << endl;
                }
            }
        }


        queue<pair<int,int>> q;
        vector<bool> vis(n,0);
        q.push({0, 1});
        vis[0]=1;
        while(!q.empty()) {
            auto top = q.front(); q.pop();
            int node = top.first;
            int hop = top.second;
            // cout << node << " " << hop << endl;
            if(node==endIndex) {
                return hop;
            }

            for(int next : adj[node]) {
                if (vis[next]==0) {
                    vis[next]=1;
                    q.push({next, hop+1});
                }
            }
        }

        return 0;




    }
};