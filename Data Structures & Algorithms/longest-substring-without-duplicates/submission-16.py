class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # advdf
        substring = []
        max_substring = 0
        for letter in s:
            while letter in substring:
                substring.pop(0)
            substring.append(letter)
            max_substring = max(max_substring, len(substring))
        
        return max_substring