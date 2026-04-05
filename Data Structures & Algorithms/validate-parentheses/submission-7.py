class Solution:
    def isValid(self, s: str) -> bool:
        brackets = {
            '(' : ')',
            '{' : '}', 
            '[' : ']'
        }

        stack = []

        for i, bracket in enumerate(s):
            if bracket in brackets.keys():
                stack.append(bracket)
            else:
                if stack and brackets[stack[-1]] == bracket:
                    stack.pop()
                else:
                    return False

        return True if not stack else False
