class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> res;
        set<pair<int,int>> visited;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> qu;

        visited.insert({0,0});
        qu.push({nums1[0]+nums2[0],{0,0}});

        while(k-- && !qu.empty()) {
            auto front = qu.top(); qu.pop();
            int diff = front.first;
            int left = front.second.first;
            int right = front.second.second;

            res.push_back({nums1[left], nums2[right]});

            if (left + 1 < n && visited.find({left+1, right})==visited.end()) {
                qu.push({nums1[left+1]+nums2[right], {left+1, right}});
                visited.insert({left+1, right});
            }
            
            if (right + 1 < m && visited.find({left, right+1})==visited.end()) {
                qu.push({nums1[left]+nums2[right+1], {left, right+1}});
                visited.insert({left, right+1});
            }
            
        }

        return res;
    }
};