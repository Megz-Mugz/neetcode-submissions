class Solution {
public:
    bool isValid(string s) {
        
        std::unordered_map<char, char> brackets = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        std::stack<char> seen;

        for (auto& letter : s){
            auto it = brackets.find(letter);

            if (it != brackets.end()){
                seen.push(letter);
            } else {
                
                if (seen.empty()) return false;

                auto top_of_stack = seen.top();

                // std::cout << brackets[top_of_stack] << std::endl;
                // std::cout << letter << std::endl;

                if (brackets[top_of_stack] == letter){
                    seen.pop();
                } else {
                    return false;
                }
            }
        }

        return seen.empty();

    }
};
