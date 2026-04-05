class Solution:
    def lengthOfLongestSubstring(self, letters: str) -> int:
        
        longest_substring = 0
        substring = set() # wke
        left = 0

        for letter in letters:

            while letter in substring:
                substring.remove(letters[left])
                left += 1
            
            substring.add(letter)
            longest_substring = max(longest_substring, len(substring))

        return max(longest_substring, len(substring))