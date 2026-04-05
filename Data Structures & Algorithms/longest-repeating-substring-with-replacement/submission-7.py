class Solution:
    def characterReplacement(self, letters: str, k: int) -> int:

        # keep track of most freqently occurring letter in window
        count = {}
        left, right = 0, 0
        output = 0
        while right < len(letters):
            count[letters[right]] = count.get(letters[right], 0) + 1

            while (right - left + 1) - max(count.values()) > k:
                count[letters[left]] -= 1
                left += 1
            
            output = max(output, right - left + 1)
            right += 1

        return output