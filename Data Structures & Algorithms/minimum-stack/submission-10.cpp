class MinStack {

private:
    std::stack<std::pair<int, int>> num_stack;

public:
    MinStack() {}
    
    void push(int val) {
        if (num_stack.empty()){
            num_stack.push({val, val});
        } else {
            num_stack.push({
                val, 
                std::min(val, num_stack.top().second)
            });
        }
    }
    
    void pop() {
        if (num_stack.empty()) return;
        num_stack.pop();
    }
    
    int top() {
        return num_stack.top().first;
    }
    
    int getMin() {
        return num_stack.top().second;
    }
};
