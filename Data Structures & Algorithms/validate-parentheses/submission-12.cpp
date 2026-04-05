class Solution {
public:
    bool isValid(string s) {
        
        std::stack<char> seen;

        for (auto& letter : s){
            if (letter == '(' || letter == '{' || letter == '[') {
                seen.push(letter);
            } else {

                if (seen.empty()) return false;

                auto topOfStack = seen.top();

                if (topOfStack == '(' && letter == ')'){
                    seen.pop();
                } else if (topOfStack == '[' && letter == ']'){
                    seen.pop();
                } else if (topOfStack == '{' && letter == '}'){
                    seen.pop();
                } else {
                    return false;
                }

            }
        }

        return (seen.empty()) ? true : false;
    }
};
