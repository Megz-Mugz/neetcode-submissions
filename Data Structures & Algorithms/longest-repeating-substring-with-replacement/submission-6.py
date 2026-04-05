class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        
        letters_and_freq = {}
        left = 0
        result = 0
        for right in range(len(s)):
            letters_and_freq[s[right]] = 1 + letters_and_freq.get(s[right], 0)

            while (right - left) + 1 - max(letters_and_freq.values()) > k:
                letters_and_freq[s[left]] -= 1
                left += 1
            
            result = max(result, (right - left) + 1)
        
        return result