class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size =nums.size();
        
        sort(nums.begin(), nums.end());
        int t;
        vector<vector<int>> result;
        for(int i=0;i<size-3;i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<size-2;j++) {
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                
                int k=j+1,l=size-1;
                
                t = target - (nums[i]+nums[j]);
                
                while (k<l) {
                    // cout << k << " " << l << endl;
                    int s2 = (nums[k]+nums[l]);
                    if (s2==t) {
                        vector<int> ans = {nums[i],nums[j],nums[k++],nums[l--]};
                        // sort(ans.begin(),ans.end());
                        result.push_back(ans);
                        
                        while (k<l && nums[k]==nums[k-1])k++;
                        while (k<l && nums[l]==nums[l+1])l--;
                    } 
                    else if (s2>t) l--; 
                    else k++; 
                    
                    // cout << k << " " << l << endl;
                }
                
            }
        }
        return result;
    }
};