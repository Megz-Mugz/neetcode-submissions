class Solution {
public:
    bool isValid(string s) {
        
        std::stack<char> seen;

        std::unordered_map<char, char> pairings = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        for (auto& letter : s){
            if (pairings.count(letter)) {
                seen.push(letter);
            } else {

                if (seen.empty()) return false;

                auto topOfStack = seen.top();

                if (pairings[topOfStack] == letter){
                    seen.pop();
                } else {
                    return false;
                }

            }
        }

        return seen.empty();
    }
};
