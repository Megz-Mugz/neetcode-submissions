class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        std::unordered_set<char> seen; // z, x, y
        size_t longest_substr = 0;

        for (int right = 0; right < s.size(); right++){
            
            while (seen.find(s[right]) != seen.end()){
                seen.erase(s[left++]);
            }

            seen.insert(s[right]);
            
            longest_substr = std::max(longest_substr, seen.size());
        }

        return longest_substr;
    }
};
