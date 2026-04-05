class Solution:
    def climbStairs(self, n: int) -> int:
        
        # decision tree starting at step 0 (ground floor)
        # keep asking urself 0 -> (1 step) or (2 step)

        # step -> # of possibilities to reach the step
        cache = {} # can hardcode all values, but that obviously defeats point

        def dfs(step):

            if step == n: return 1 # reached the correct step!

            if step > n: return 0 # overshot, no path

            if step in cache: return cache[step]

            cache[step] = dfs(step + 1) + dfs(step + 2)
            return cache[step]

        print(cache)
        return dfs(0)