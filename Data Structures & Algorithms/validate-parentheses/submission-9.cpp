class Solution {
public:
    bool isValid(string s) {
        
        std::stack<char> seen;

        for (auto letter : s){
            if (letter == '[' || letter == '{' || letter == '('){
                seen.push(letter);
            } else {
                if (seen.empty()) return false;

                char top = seen.top();
                seen.pop();

                if ((letter == ')' && top != '(') || (letter == ']' && top != '[') ||  (letter == '}' && top != '{')) {
                    return false;
                }
            }
        }

        return seen.empty();
    }
};
