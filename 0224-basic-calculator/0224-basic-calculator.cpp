class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sign = 1, number = 0, result = 0;

        for(int i=0;i<s.size();i++) {

            char c = s[i];

            if (c==' ') continue;

            if (isdigit(c)) {
                number = number*10 + (c-'0');
            } else if (c=='+') {
                result += sign * number;
                number = 0;
                sign = 1;
            } else if (c=='-') {
                result += sign * number;
                number = 0;
                sign = -1;
            } else if (c=='(') {
                st.push(result);
                st.push(sign);
                result = 0; sign = 1;
            } else {
                result += sign * number;
                number = 0;
                result *= st.top(); st.pop();
                result += st.top(); st.pop();
            }
        }

        result += sign * number;

        return result;
    }
};