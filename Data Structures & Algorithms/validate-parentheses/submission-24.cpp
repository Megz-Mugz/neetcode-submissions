class Solution {
public:
    bool isValid(string parenthesis_string) {
        
        // Maps opening and closing parenthesis
        std::unordered_map<char, char>  parenthesis_map = {
            {'(', ')'}, 
            {'{', '}'}, 
            {'[', ']'}
        };

        std::stack<char> open_parenthesis;

        for (auto curr_parenthesis : parenthesis_string){
            
            // if it's an open parenthesis, push to stack
            if (parenthesis_map.contains(curr_parenthesis)){
                open_parenthesis.push(curr_parenthesis);
            
            // if it's a closing parenthesis, check if the last value in stack 
            // can work with this parenthesis
            } else {
                if (!open_parenthesis.empty()){
                    auto last_open_paren = open_parenthesis.top();
                    if (parenthesis_map[last_open_paren] != curr_parenthesis) return false;
                    open_parenthesis.pop();
                } else {
                    return false;
                }
            }
           
        }

        return open_parenthesis.empty();
    }
};
