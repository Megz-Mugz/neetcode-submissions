class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()

        left = 0
        right = len(s) - 1

        # 2 loops one for left ptr and another for right ptr
        # if letter is NOT alphanum, then 

        while left < right:

            while (not s[left].isalnum() and left < right):
                left += 1
            while (not s[right].isalnum() and left < right):
                right -= 1
            if s[left] != s[right]:
                return False
            else:
                left += 1
                right -= 1
        return True
