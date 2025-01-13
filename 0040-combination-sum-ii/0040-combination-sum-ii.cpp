class Solution {
public:
    void recur(int index, vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& res) {
        if (target==0) {
            res.push_back(temp);
            return;
        }

        if (index==nums.size()) return;

        if (nums[index]<=target) {
            temp.push_back(nums[index]);
            recur(index+1, nums, target - temp.back(), temp, res);
            temp.pop_back();
        }
        while(index < nums.size()-1 && nums[index]==nums[index+1]) index++;

        recur(index+1, nums, target, temp, res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;

        vector<vector<int>> res;
        recur(0,candidates, target, temp, res);

        return res;
    }
};