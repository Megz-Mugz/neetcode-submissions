class Solution {
public:
    bool isValid(string s) {
        std::stack<char> visited;

        std::unordered_map<char, char> brackets = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        for (auto& letter : s){
            if (letter == '(' || letter == '{' || letter == '['){
                visited.push(letter);
            } else {
                if (visited.empty()) return false;

                auto top_of_stack = visited.top();
                auto it = brackets.find(top_of_stack);

                if (it != brackets.end() && it->second == letter){
                    visited.pop();
                } else{
                    return false;
                }
            }
        }



        return visited.empty();
    }
};
