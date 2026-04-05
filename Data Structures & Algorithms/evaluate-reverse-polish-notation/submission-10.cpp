class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> num_stack;
        int answer{};
        for (const auto& num_str : tokens){
            
            if (num_str == "+" || num_str == "-" || num_str == "*" || num_str == "/"){
                auto second_num = num_stack.top(); num_stack.pop();
                auto first_num = num_stack.top(); num_stack.pop();

                if (num_str == "+"){
                    answer = first_num + second_num;
                } else if (num_str == "-"){
                    answer = first_num - second_num;
                } else if (num_str == "*"){
                    answer = first_num * second_num;
                } else {
                    answer = first_num / second_num;
                }
                num_stack.push(answer);
            } else {
                num_stack.push(std::stoi(num_str));
            }

        }

        return num_stack.top();
    }
};
