class Solution {
vector<int> findNGE(vector<int>& h ) {
        int n = h.size();
        stack<int> st;
        vector<int> nse(n,-1);
        st.push(h[h.size()-1]);

        for(int i=n-2;i>=0;i--) {
            while(!st.empty() && st.top()<=h[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nse[i]=st.top();
            }
            st.push(h[i]);
        }

        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && st.top()<=h[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nse[i]=st.top();
            }
            st.push(h[i]);
        } 

        return nse;
    }
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        return findNGE(nums);
    }
};