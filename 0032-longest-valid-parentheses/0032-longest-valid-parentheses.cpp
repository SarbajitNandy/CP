class Solution {
private:
    int find(string s) {
        stack<int> st;

        for(int i=0;i<s.length();i++) {
            if (s[i]=='(') st.push(i);
            else if (st.size()){
                s[st.top()]=s[i]='*';
                st.pop();
            }
        }

        int curr = 0, ans = 0;

        for(int i=0;i<=s.length();i++) {
            if (s[i]=='*') curr++;
            else {
                ans = max(ans, curr); curr = 0;
            }
        }

        return max (ans, curr);
    }

public:
    int longestValidParentheses(string s) {
        

        return find(s);
    }
};