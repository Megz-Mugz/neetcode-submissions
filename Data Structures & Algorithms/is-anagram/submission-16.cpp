class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> s_letters;
        std::unordered_map<char, int> t_letters;

        for (const auto& letter : s){
            s_letters[letter]++;
        }

        for (const auto& letter : t){
            t_letters[letter]++;
        }

        return s_letters == t_letters;
        
    }
};
