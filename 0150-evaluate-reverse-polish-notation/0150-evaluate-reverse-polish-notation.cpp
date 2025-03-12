class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string e : tokens) {
            if (e=="+" || e=="-" || e=="/" || e=="*") {
                int op2 = st.top(); st.pop();
                int op1 = st.top(); st.pop();
                switch(e[0]) {
                    case '+':   op1 = op1+op2; break;
                    case '-':   op1 = op1-op2; break;
                    case '*':   op1 = op1*op2; break;
                    case '/':   op1 = op1/op2; break;
                }
                st.push(op1);
            } else {
                st.push(stoi(e));
            }
        }

        return st.top();
    }
};