class MinStack {
private:
    std::stack<int> num_stack;
    std::stack<int> min_stack;
public:
    MinStack() {}
    
    void push(int val) {
        
        if (num_stack.empty()){
            min_stack.push(val);
        } else {
            min_stack.push(std::min(val, min_stack.top()));
        }
        num_stack.push(val);
    }
    
    void pop() {
        if (num_stack.empty()) return;

        num_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return num_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
