class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k==1) return nums;

        int n = nums.size();
        deque<int> qu;
        vector<int> res;

        for(int i=0;i<k;i++) {
            while(!qu.empty() && nums[qu.back()]<=nums[i]) {
                qu.pop_back();
            }
            qu.push_back(i);
        }
        res.push_back(nums[qu.front()]);

        for(int i=k;i<n;i++) {
            if (qu.front()==i-k) {
                qu.pop_front();
            }

            while(!qu.empty() && nums[qu.back()]<=nums[i]) {
                qu.pop_back();
            }

            qu.push_back(i);

            res.push_back(nums[qu.front()]);
        }

        return res;
    }
};