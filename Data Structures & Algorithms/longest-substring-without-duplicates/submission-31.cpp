class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        std::unordered_set<int> seen_chars;
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
            curr_len = seen_chars.size();
            longest_substr = std::max(longest_substr, curr_len);
            i++;
        }
 
        return longest_substr;
    }
};
