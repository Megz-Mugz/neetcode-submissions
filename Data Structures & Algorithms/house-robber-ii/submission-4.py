class Solution:
    def rob(self, nums: List[int]) -> int:
        
        N = len(nums)
        if N == 1: return nums[0]

        def dfs(index, end, cache):

            if index > end: return 0

            if index in cache: return cache[index]

            cache[index] = max(
                nums[index] + dfs(index + 2, end, cache), # rob and then skip to next non-adjacent house
                dfs(index + 1, end, cache) # don't rob and skip to next house
            )

            return cache[index]

        return max(
            dfs(index=0, end=N-2, cache={}), 
            dfs(index=1, end=N-1, cache={})
        )