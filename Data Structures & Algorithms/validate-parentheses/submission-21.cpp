class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> parens = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        std::stack<char> seen;

        for (const auto& curr_paren : s){
            // if it's an opening parenthesis, add to stack
            if (parens.contains(curr_paren)){
                seen.push(curr_paren);
            } else {
                // if it's a closing parenthesis, check if it corresponds
                // with the top of stack
                
                // to avoid starting a string with a closing parenthesis, 
                // check if we have already seen opening parenthesis
                if (seen.empty()) return false;
                auto opening_paren = seen.top();

                // check if the opening parenthesis matches with the closing parenthesis
                if (parens[opening_paren] != curr_paren) return false;
                // upon valid match, remove the opening parenthesis from stack
                seen.pop(); 
            }
        }

        // handle the case where an opening parenthesis is still in the stack
        return seen.empty();

    }
};
