class MinStack {
public:
    stack<int> st, mn;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mn.push(min(val,mn.empty() ? INT_MAX : mn.top()));
    }
    
    void pop() {
        st.pop();
        mn.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */