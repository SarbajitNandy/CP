class Solution {
private:
    vector<int> findNSE(vector<int>& h ) {
        int n = h.size();
        stack<int> st;
        vector<int> nse(n,-1);
        st.push(h.size()-1);

        for(int i=n-2;i>=0;i--) {
            while(!st.empty() && h[st.top()]>=h[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nse[i]=st.top();
            }
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
        vector<int> pse(h.size(),-1);
        st.push(0);

        for(int i=1;i<n;i++) {
            while(!st.empty() && h[st.top()]>=h[i]) {
                st.pop();
            }

            if (!st.empty()) {
                pse[i]=st.top();
            }
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
        auto pse = findPSE(heights);
        auto nse = findNSE(heights);
        int n = heights.size();
        int res = 0;

        for(int i=0;i<heights.size();i++) {
            res = max(res, ((nse[i]==-1 ? n : nse[i])-pse[i]-1)*heights[i]);
        }

        return res;
    }
};

/*
2,1,5,6,2,3
1  -1  2  2  -1  -1

-1 -1 1 5 1 2

*/