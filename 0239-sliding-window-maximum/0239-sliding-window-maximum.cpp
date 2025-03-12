class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& input, int k) {
        if (k==1) return input;
        int n = input.size();

        deque<int> q;
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            while (!q.empty() && q.back() < input[i]) {
                q.pop_back();
            }
            q.push_back(input[i]);
        }
        ans.push_back(q.front());

        for (int i = k; i < n; i++) {
            if (q.front() == input[i - k])
                q.pop_front();

            while (!q.empty() && q.back() < input[i]) {
                q.pop_back();
            }
            q.push_back(input[i]);
            ans.push_back(q.front());
        }

        return ans;
    }
};