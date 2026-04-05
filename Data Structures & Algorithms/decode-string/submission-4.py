class Solution:
    def decodeString(self, s: str) -> str:
        
        stack = []

        for letter in s:

            if letter != ']':
                stack.append(letter)
            else:
                # build substring
                sub_str = ""
                while stack and stack[-1] != '[':
                    sub_str = stack.pop() + sub_str
                stack.pop() # breaks once it detects [ and pops it

                # handle number
                number = ""
                while stack and stack[-1].isdigit():
                    number = stack.pop() + number

                stack.append(sub_str * int(number))

        print(f'stack: {stack} sub_str: {sub_str}')
        return ''.join(stack)

                    

