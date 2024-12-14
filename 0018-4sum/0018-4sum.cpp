class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        int d = n-1, c = n-2, a = 0,b=n-3;
        set<vector<int>> res;
        sort(nums.begin(), nums.end());

        while(d >= 3) {
            c = d-1;
            while(c>=2) {
                b = c-1;a=0;
                long long sum = target;
                sum-=nums[d];
                sum-=nums[c];

                while(a < c && b>=0 && a < b) {
                    int s = nums[a]+nums[b];
                    if (nums[a]+nums[b] == sum) {
                        res.insert({nums[a],nums[b], nums[c], nums[d]});
                        // while(a < c-1 && nums[a]==nums[a+1]) a++;
                        // while(b>0 && nums[b]==nums[b-1]) b--;

                        a++;b--;
                        // cout <<  a << " " << b << endl;
                    } else if (s < sum) {
                        a++;
                    } else b--;
                }
                c--;
            }
            d--;
        }

        return vector<vector<int>>(res.begin(), res.end());
    }
};