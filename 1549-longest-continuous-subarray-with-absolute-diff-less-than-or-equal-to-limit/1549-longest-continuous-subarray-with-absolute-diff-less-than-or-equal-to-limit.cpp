class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxQ, minQ;
        int left = 0, ans = 0;
        int n = nums.size();

        for (int right = 0;right < n; right++) {
            while(!maxQ.empty() && nums[right] > maxQ.back()) {
                maxQ.pop_back();
            } 
            maxQ.push_back(nums[right]);

            while(!minQ.empty() && nums[right] < minQ.back()) {
                minQ.pop_back();
            } 
            minQ.push_back(nums[right]);


            while(!maxQ.empty() && !minQ.empty() && maxQ.front() - minQ.front() > limit) {
                if (maxQ.front() == nums[left]) maxQ.pop_front();
                if (minQ.front() == nums[left]) minQ.pop_front();
                left++;
            }

            ans = max(ans, right - left + 1);


        }

        return ans;
    }
};