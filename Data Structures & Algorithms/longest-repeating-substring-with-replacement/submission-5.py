class Solution:
    def characterReplacement(self, string: str, k: int) -> int:
        count = {}
        result = 0
        left = 0

        for right in range(len(string)):
            count[string[right]] = 1 + count.get(string[right], 0)

            while (right - left) + 1 - max(count.values()) > k:
                count[string[left]] -= 1
                left += 1
             
            result = max(result, (right - left) + 1)
        
        return result