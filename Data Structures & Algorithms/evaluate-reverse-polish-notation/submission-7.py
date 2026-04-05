class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        
        stack = []

        # push numbers into stack
        # if you come across a math operation, do the operation
        # take the result of the operation and push to stack too
        # return the last value of the stack


        for token in tokens:

            if token not in "+-*/":
                stack.append(int(token))
            else:
                result = 0
                second_num = stack.pop()
                first_num = stack.pop()
                print(f'first_num: {first_num} second_num: {second_num}')
                match token:
                    case "+":
                        result = second_num + first_num
                    case "-":
                        result = first_num - second_num
                    case "*":
                        result = first_num * second_num
                    case "/":
                        result = first_num / second_num
                stack.append(int(result))
        
        return stack[-1]


