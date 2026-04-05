class Solution:
    def isPalindrome(self, s: str) -> bool:

        left_ptr = 0
        right_ptr = len(s) - 1

        while left_ptr < right_ptr:
            while not s[left_ptr].isalnum() and left_ptr < right_ptr:
                left_ptr += 1

            while not s[right_ptr].isalnum() and right_ptr > left_ptr:
                right_ptr -= 1
            
            print(f'comparing {s[left_ptr]} and {s[right_ptr]}')
            if s[left_ptr].lower() != s[right_ptr].lower():
                return False
            else:
                left_ptr += 1
                right_ptr -= 1
            
        return True
        