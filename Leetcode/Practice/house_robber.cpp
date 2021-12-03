class Solution {
public:
    int rob(vector<int>& nums) {
        int incld=0, excld=0;
        for(auto each:nums) {
            int x = incld;
            incld = excld + each;
            excld=max(x,excld);
        }
        return max(incld, excld);
    }
};