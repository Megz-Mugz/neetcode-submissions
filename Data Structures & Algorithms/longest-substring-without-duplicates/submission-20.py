class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # advdf
        substring = set()
        max_substring = 0
        left = 0

        for letter in s:

            while letter in substring:
                substring.remove(s[left])
                left += 1
            
            substring.add(letter)
            max_substring = max(max_substring, len(substring))
        
        return max_substring