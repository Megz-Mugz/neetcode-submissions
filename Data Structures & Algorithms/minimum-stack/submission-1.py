class MinStack:

    def __init__(self):
        self.stack = []
        self.stack_of_mins = []
        self.size_of_stack = 0


    def push(self, val: int) -> None:
        if self.size_of_stack == 0:
            self.stack_of_mins.append(val)
        else:
            if val <= self.stack_of_mins[-1]:
                self.stack_of_mins.append(val)
        
        self.stack.append(val)

        self.size_of_stack += 1
        

    def pop(self) -> None:
            if (self.stack[-1] == self.stack_of_mins[-1]):
                self.stack_of_mins.pop()
            self.stack.pop()
            self.size_of_stack -= 1
        

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.stack_of_mins[-1]
