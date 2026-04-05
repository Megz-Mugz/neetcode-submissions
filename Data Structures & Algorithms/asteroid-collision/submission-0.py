class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []

        for asteroid in asteroids:

            crushed = False

            while stack and stack[-1] > 0 and asteroid < 0:
                
                if abs(stack[-1]) < abs(asteroid):
                    stack.pop()
                elif abs(stack[-1]) == abs(asteroid):
                    stack.pop()
                    crushed = True
                    break
                else:
                    crushed = True
                    break

            if not crushed: stack.append(asteroid)

        return stack