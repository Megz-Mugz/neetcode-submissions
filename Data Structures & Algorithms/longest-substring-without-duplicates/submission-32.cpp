class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        std::unordered_set<char> seen_chars;
        int longest_substr = 0;
        int i{};
        int curr_len;
        int start = 0;
        while (i < str.size()){

            while (seen_chars.find(str[i]) != seen_chars.end()){
                seen_chars.erase(str[start]);
                start++;
            }
            seen_chars.insert(str[i]);
            longest_substr = std::max(longest_substr, static_cast<int>(seen_chars.size()));
            i++;
        }
 
        return longest_substr;
    }
};
