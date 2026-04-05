class MinStack {
private:
    std::stack<long> num_stack;
    std::stack<long> min_stack;
public:
    MinStack() {}
    
    void push(int val) {
        
        if (num_stack.empty()){
            min_stack.push(val);
        } else {
            min_stack.push((val < min_stack.top()) ? val : min_stack.top());
        }
        num_stack.push(val);
    }
    
    void pop() {
        if (num_stack.empty()) return;

        num_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        if (num_stack.empty()) return -1;

        return num_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
