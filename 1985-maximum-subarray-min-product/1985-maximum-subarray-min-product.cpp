class Solution {
public:
    const int MOD = 1e9+7;
    int maxSumMinProduct(vector<int>& nums) {
        priority_queue<int,vector<int>, greater<int>> pq;
        int n = nums.size();
        vector<long long> prefix(n+1, 0);
        stack<pair<int,int>> st;
        long long mx = 0;

        for(int i=1;i<=n;i++) {
            prefix[i] = prefix[i-1]+nums[i-1];
        }

        for(int i=0;i<n;i++) {
            int newStart = i;

            while(!st.empty() && st.top().second>nums[i]) {
                auto top = st.top(); st.pop();
                newStart = top.first;
                long long sum = prefix[i]-prefix[newStart];

                mx = max(mx, sum * top.second);
            }

            st.push({newStart,nums[i]});
        }

        while(!st.empty()) {
            auto top = st.top(); st.pop();
            long long sum = prefix[n]-prefix[top.first];
            mx = max(mx, (top.second * sum));
        }

        return mx%MOD;
    }
};