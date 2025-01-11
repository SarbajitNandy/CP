class Solution {
public:
    vector<vector<int>> dp;
    int recur(int left, int right, vector<int>& nums, bool take) {
        if (left > right)
            return 0;

        if (dp[left][right]!=-1) return dp[left][right];

        if (take) {
            return dp[left][right]=max(nums[left] + recur(left + 1, right, nums, !take),
                       nums[right] + recur(left, right - 1, nums, !take));
        } else {
            return dp[left][right]=min(recur(left + 1, right, nums, !take),
                       recur(left, right - 1, nums, !take));
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        dp = vector<vector<int>>(21, vector<int>(21,-1));
        int total = accumulate(nums.begin(), nums.end(), 0);

        int p1 = recur(0, nums.size() - 1, nums, true);
        return p1 >= (total - p1);
    }
};