class Solution:
    def isValid(self, s: str) -> bool:

        pairs = {
            '(' : ')', 
            '{' : '}', 
            '[' : ']'
        }
        stack = []

        for bracket in s:
            if bracket in pairs.keys():
                stack.append(bracket)
            else:
                if len(stack) <= 0:
                    return False
                if pairs[stack[-1]] != bracket:
                    return False
                else:
                    stack.pop()

        if len(stack) == 0:
            return True
        else: 
            return False
