class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numbers;

        for (const auto& token : tokens){
            if (token == "+" || token == "-" || token == "*" || token == "/"){
                auto second_num = numbers.top();
                numbers.pop();

                auto first_num = numbers.top();
                numbers.pop();

                if (token == "+")
                    numbers.push(first_num + second_num);
                else if (token == "-")
                    numbers.push(first_num - second_num);
                else if (token == "*")
                    numbers.push(first_num * second_num);
                else if (token == "/")
                    numbers.push(first_num / second_num);
            }
            else {
                numbers.push(std::stoi(token));
            }
        }

        return numbers.top();
    }
};