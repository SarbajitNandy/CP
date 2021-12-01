class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        size_t size =nums.size();
        sort(nums.begin(),nums.end());
        int pc,pa,pb,c;
        for(int pc=size-1;pc>=2;pc--) {
            if (pc==size-1 || (pc >0 && nums[pc]!=nums[pc+1])) {
                pa=0;pb=pc-1;
                while(pa<pb) {
                    c=nums[pa]+nums[pb];
                    if (c+nums[pc]==0){ 
                        vector<int> v{{nums[pa], nums[pb], nums[pc]}};
                        // sort(v.begin(),v.end());
                        ans.push_back(v); 
                        while (pa<pb && nums[pa]==nums[pa+1])pa++;
                        while (pa<pb && nums[pb]==nums[pb-1])pb--;

                        pa++;pb--;}
                    else if (c>(-nums[pc])) pb--;
                    else pa++;
                }
            }
        }
        
        return ans;
    }
};