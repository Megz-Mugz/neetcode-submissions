class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> s_map;
        std::unordered_map<char, int> t_map;


        // build out s map
        for (int i{}; i < s.size(); i++){
            s_map[s[i]] += 1;
        }

        // build out t map
        for (int i{}; i < t.size(); i++){
            t_map[t[i]] += 1;
        }


        return s_map == t_map;
    }
};
