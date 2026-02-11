class MinStack {
    stack<int> st;
    stack<int> min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push(val);
            min.push(val);
        }
        else{
            if(val<=min.top()) {
                min.push(val);
            }
            st.push(val);
        }
    }
    
    void pop() {
        if(min.top() == st.top()) {
            st.pop();
            min.pop();
        }
        else{
            st.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
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