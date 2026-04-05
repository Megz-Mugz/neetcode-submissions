class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> seen;
        int left = 0;
        int longest = 0;

        for (int right = 0; right < s.size(); right++){
            
            if (seen.find(s[right]) != seen.end()){
                while (seen.find(s[right]) != seen.end()){
                    seen.erase(s[left]);
                    left++;
                }
            }
            seen.insert(s[right]);
            longest = std::max(longest, right - left + 1);
        }

        return longest;
    }
};
