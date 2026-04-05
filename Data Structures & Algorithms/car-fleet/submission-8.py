class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        
        # leverage the fact that you can pre-compute the time to reach destination using math

        pos_and_speed = sorted(zip(position, speed), reverse=True)
        print(pos_and_speed)

        stack = []
        for i in range(len(pos_and_speed)):
            pos, speed = pos_and_speed[i]
            till_target = (target - pos) / speed

            if not stack or till_target > stack[-1]:
                stack.append(till_target)
        
        return len(stack)
        