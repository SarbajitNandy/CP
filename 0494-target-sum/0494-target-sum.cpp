class Solution {
public:

    // int recur(int id, int target, vector<int>& nums, vector<vector<int>>& dp) {
    //     if (id==0) {
    //         if (target==0 && nums[0]==0) return 2;
    //         else if (target==0 || target==nums[0]) return 1;
    //         return 0;
    //     }

    //     if (dp[id][target]!=-1) return dp[id][target];
    //     int np = recur(id-1, target, nums, dp);
    //     int p = 0;
    //     if (target>=nums[id]) {
    //         p = recur(id-1, target-nums[id], nums, dp);
    //     }

    //     return dp[id][target]=np+p;
    // }
    int find(int target, vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(target+1, 0));
        if (nums[0]==0) dp[0][0]=2;
        else dp[0][0]=1;

        if ( nums[0]!=0 && target>=nums[0]) dp[0][nums[0]]=1;

        for(int i=1;i<nums.size();i++) {
            for(int sum=0;sum<=target;sum++) {
                int np = dp[i-1][sum];
                int p=0;

                if (sum>=nums[i]) {
                    p= dp[i-1][sum-nums[i]];
                }

                dp[i][sum]=np+p;
            }
        }

        return dp[nums.size()-1][target];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = (total+target);
        if (sum <0 || sum%2!=0) return 0;  

        return find(sum/2,nums);
    }
};