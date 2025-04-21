class Solution {
private:
    vector<int> pse(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            res[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return res;
    }
    vector<int> nse(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            res[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return res;
    }

    int largestHistogram(vector<int>& histo) {
        int maxi = 0;
        auto ns = nse(histo);
        auto ps = pse(histo);

        for (int i = 0; i < histo.size(); i++) {
            // cout << (ns[i]-ps[i]-1) << endl;
            maxi = max(maxi, (ns[i] - ps[i] - 1) * histo[i]);
            // cout << maxi << endl;
        }

        return maxi;
    }

public:

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        int maxArea = 0;
        vector<int> height(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            int area = largestHistogram(height);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};