class Solution {
private:
    vector<int> findNSE(vector<int>& h ) {
        int n = h.size();
        stack<int> st;
        vector<int> nse(n,0);
        // st.push(h.size()-1);

        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && h[st.top()]>=h[i]) {
                st.pop();
            }

            // if (!st.empty()) {
                nse[i]=st.empty()? n : st.top();
            // }
            st.push(i);
        } 


        // for(int e : nse) {
        //     cout << e << " ";
        // }

        // cout << endl;

        return nse;
    }
    vector<int> findPSE(vector<int>& h ) {
        int n = h.size();
        stack<int> st;
        vector<int> pse(h.size(),0);
        // st.push(0);

        for(int i=0;i<n;i++) {
            while(!st.empty() && h[st.top()]>=h[i]) {
                st.pop();
            }

            // if (!st.empty()) {
                pse[i]=st.empty() ? -1 : st.top();
            // }
            st.push(i);
        } 

        // for(int e : pse) {
        //     cout << e << " ";
        // }

        // cout << endl;

        return pse;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size()==1) return heights[0];
        auto pse = findPSE(heights);
        auto nse = findNSE(heights);
        int n = heights.size();
        int res = 0;

        for(int i=0;i<heights.size();i++) {
            res = max(res, (nse[i]-pse[i]-1)*heights[i]);
        }

        return res;
    }
};