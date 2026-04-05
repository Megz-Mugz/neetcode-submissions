class Solution:
    def lengthOfLongestSubstring(self, letters: str) -> int:
        
        longest_substring = 0
        substring = ""

        for letter in letters:

            while letter in substring:
                substring = substring[1:]
            
            substring += letter
            longest_substring = max(longest_substring, len(substring))

        return max(longest_substring, len(substring))