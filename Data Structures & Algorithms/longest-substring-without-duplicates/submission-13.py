class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        left, right, max_substring = 0, 0, 0
        substring = set()
        
        while right < len(s):
            max_substring = max(max_substring, len(substring))
            while s[right] in substring:
                substring.remove(s[left])
                left += 1
            substring.add(s[right])
            right += 1
        return max(max_substring, len(substring))