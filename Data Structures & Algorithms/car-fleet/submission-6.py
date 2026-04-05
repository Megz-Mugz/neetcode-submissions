class Solution:
    def carFleet(self, target: int, positions: List[int], speeds: List[int]) -> int:
        
        position_speed = [[position, speed] for position, speed in zip(positions, speeds)]
        position_speed.sort(reverse=True, key = lambda item : item[0])
        print(position_speed)
        stack = []

        for position, speed in position_speed:
            time = (target - position) / speed
            print(f'time: {time}') 
            if not stack or time > stack[-1]:
                stack.append(time)
        return len(stack)