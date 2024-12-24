class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0, ans = 0;

        for(int i=0;i<=31;i++) {
            for(int e : nums) {
                if ((e>>i) & 1) {
                    sum++;
                }
            }

            if (sum%3!=0) {
                ans |= (1<<(i));
            };
            sum=0; 
        }

        return ans;
    }
};