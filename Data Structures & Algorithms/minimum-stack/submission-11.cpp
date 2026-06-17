class MinStack {
private:
    std::stack<int> numbers_stack;
    std::stack<int> min_stack;

public:
    MinStack() {}
    
    void push(int val) {
        numbers_stack.push(val);
        min_stack.push(
            std::min(val, min_stack.empty() ? val : min_stack.top())
        );
    }
    
    void pop() {
        numbers_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return numbers_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
