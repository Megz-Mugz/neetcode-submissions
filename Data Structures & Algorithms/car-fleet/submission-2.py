class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        
        pair = [[position, speed] for position, speed in zip(position, speed)]
        stack = []
        for position, speed in sorted(pair)[::-1]:
            stack.append((target - position) / speed)
            if len(stack) >= 2 and stack[-1] <= stack[-2]:
                stack.pop()
        
        return len(stack)