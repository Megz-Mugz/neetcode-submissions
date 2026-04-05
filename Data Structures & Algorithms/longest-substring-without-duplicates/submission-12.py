class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
            
        left, right = 0, 1
        substring = set(s[left])
        max_substring = 0
        while right < len(s):
            max_substring = max(max_substring, len(substring))
            while s[right] in substring:
                substring.remove(s[left])
                left += 1
            substring.add(s[right])
            right += 1
        return max(max_substring, len(substring))