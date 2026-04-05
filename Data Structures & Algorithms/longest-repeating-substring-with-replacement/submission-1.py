class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}
        output_max = 0
        left = 0

        for right in range(len(s)):
            count[s[right]] = count.get(s[right], 0) + 1

            if ((right - left + 1) - max(count.values()) > k):
                count[s[left]] -= 1
                left += 1
            
            output_max = max(output_max, (right - left + 1))
            
        return output_max

            



