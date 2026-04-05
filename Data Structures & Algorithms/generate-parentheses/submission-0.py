class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        # only add open parenthesis if open < n
        # n open parenthesis, n closing parenthesis (n * 2 total parenthesis)
        # only if the close count < open count, you can add a closing 

        stack = []
        res = []

        def backtrack(openN, closedN):

            if openN == closedN == n:
                res.append("".join(stack))
            
            if openN < n:
                stack.append("(")
                backtrack(openN + 1, closedN)
                stack.pop()
            
            if closedN < openN:
                stack.append(")")
                backtrack(openN, closedN + 1)
                stack.pop()
        
        backtrack(0, 0)
        return res
