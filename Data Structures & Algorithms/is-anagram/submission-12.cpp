class Solution {
public:
    bool isAnagram(string s, string t) {
        // if the lengths aren't equal, automatically return false
        if (s.length() != t.length()) return false;

        // make hash maps for each with letter -> freq
        unordered_map<char, int> s_letters, t_letters;

        for (int i{}; i < s.length(); i++){
            char s_letter = s[i];
            char t_letter = t[i];

            // increment frequency for each letter
            s_letters[s_letter]++;
            t_letters[t_letter]++;
        }
        

        // return hashmap_1 == hashmap_2
        return s_letters == t_letters;
    }
};
