class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;

        for (const auto _char : s){
            s_map[_char]++;
        }

        for (const auto _char : t){
            t_map[_char]++;
        }

        return s_map == t_map;
    }
};
