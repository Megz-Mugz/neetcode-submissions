class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> parens = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        std::stack<char> seen; // (, [, {

        for (const auto& curr_paren : s){
            // if it's an opening parenthesis, add to stack
            if (parens.contains(curr_paren)){
                seen.push(curr_paren);
            } else {
                if (seen.empty()) return false;
                auto opening_paren = seen.top();

                if (parens[opening_paren] != curr_paren) return false;
                seen.pop();
            }
        }

        return seen.empty();

    }
};
