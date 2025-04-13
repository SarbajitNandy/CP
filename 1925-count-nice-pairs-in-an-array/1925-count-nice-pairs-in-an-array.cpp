class Solution {

private:
    int rev(int num) {
        int res = 0;

        while (num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }

        return res;
    }

public:
    int countNicePairs(vector<int>& nums) {
        int MOD = 1e9 + 7;
        unordered_map<int, long long> freqs;

        long long count = 0;

        for (int num : nums) {
            int val = num - rev(num);

            count = ((count + freqs[val]) % MOD);

            freqs[val] = ((freqs[val] + 1) % MOD);
        }

        return count;
    }
};