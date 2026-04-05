class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 1 or len(s) == 0:
            return len(s)

        left = 0
        right = 1
        seen = []
        seen.append(s[left])
        max_substring = 0
        while right < len(s):

            if s[left] != s[right] and s[right] not in seen:
                seen.append(s[right])
                right += 1
            else:
                max_substring = max(len(seen), max_substring)
                i = seen.index(s[right])
                seen = seen[i+1:]
                seen.append(s[right])
                left = right
                right += 1
        return max(max_substring, len(seen))