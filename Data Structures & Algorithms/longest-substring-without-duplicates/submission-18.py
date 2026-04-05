class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # advdf
        substring = set()
        max_substring = 0
        left = 0

        for right in range(len(s)):

            while s[right] in substring:
                substring.remove(s[left])
                left += 1
            substring.add(s[right])
            max_substring = max(max_substring, (right - left) + 1)
        
        return max_substring