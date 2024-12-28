class Solution {
public:
    int preimageSizeFZF(int k) {
        vector<int> sum(13, 1);

        for (int i = 1; i < 13; i++)
            sum[i] = sum[i - 1] * 5 + 1;
        for (int i = 12; i >= 0; i--) {
            if (k / sum[i] == 5)
                return 0;
            k = k % sum[i];
        }
        return 5;
    }
};