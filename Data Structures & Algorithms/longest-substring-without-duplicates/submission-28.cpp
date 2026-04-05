class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        std::unordered_set<char> uniqSubstring;
        int left = 0;        
        int longestSubstring = 0;

        for (int right = 0; right < s.size(); right++){

            while (uniqSubstring.count(s[right])){
                // remove left most value from substring
                uniqSubstring.erase(s[left++]);
            } 
            uniqSubstring.insert(s[right]);

            // save the length of longest substring w/o duplicate
            longestSubstring = max((int)uniqSubstring.size(), longestSubstring);
        }
        return longestSubstring;
    }
};
