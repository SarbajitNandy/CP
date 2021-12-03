class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       int n = nums.size();
        vector<int> ans(n,0);
        int idx=0;
        for(int i=n-1;i>=0;i--) {
            
            if (i==n-1) {
                while(i!=idx && nums[idx]<=nums[i])idx=(idx+1)%n;
                if (i==idx){ans[i]=-1;}
                else {ans[i]=nums[idx];}
            } else {
                if (nums[i]<nums[i+1])ans[i]=nums[i+1];
                else if (nums[i]==nums[i+1]) ans[i]=ans[i+1];
                else {
                    if (nums[i]>=ans[i+1]){
                        idx=i+1;
                        while(i!=idx && nums[idx]<=nums[i])idx=(idx+1)%n;
                        if (i==idx){ans[i]=-1;}
                        else {ans[i]=nums[idx];}
                    }
                    else ans[i]=ans[i+1];
                }
            }
        }
        return ans;
    }
};
