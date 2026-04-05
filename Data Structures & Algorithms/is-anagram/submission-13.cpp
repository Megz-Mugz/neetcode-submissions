class Solution {
public:
    bool isAnagram(string s, string t) {
        // if the lengths aren't equal, automatically return false
        if (s.length() != t.length()) return false;

        // make hash maps for each with letter -> freq
        unordered_map<char, int> freq;

        for (int i{}; i < s.length(); i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }

        // traverse ordered map
        for (auto [_, frequency] : freq){
            if (frequency != 0) return false;
        }
        
        return true;
    }
};
