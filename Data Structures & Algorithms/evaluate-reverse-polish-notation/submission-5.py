class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        nums_stack = [] 
        for token in tokens:
            try:
                nums_stack.append(int(token))
            except:
                print(nums_stack)
                second_num = nums_stack.pop()
                first_num = nums_stack.pop()
                result = eval(f"{first_num} {token} {second_num}")
                print(result)
                nums_stack.append(int(result))
        return int(nums_stack[0])