class Solution {
public:

    void recur(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& res) {
        if (index == nums.size()) {
            res.push_back(temp);
            return;
        }

        // for(int i=index;i<nums.size();i++) {
        //     if (i!=index && nums[i]==nums[index]) continue;
            temp.push_back(nums[index]);
            recur(index+1, nums,temp, res);
            temp.pop_back();

            while(index<nums.size()-1 && nums[index+1]==nums[index]) index++;
            recur(index+1, nums,temp, res);

        // }
    } 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        vector<vector<int>> res;

        recur(0,nums, temp, res);
        
        return res;
    }
};