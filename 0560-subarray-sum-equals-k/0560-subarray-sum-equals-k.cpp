class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        int cnt=0, pre=0;
        mp[0]=1;
        for(int e : nums) {
            pre+=e;

            cnt += mp[pre-k];
            mp[pre]++;
        }

        return cnt;
    }
};