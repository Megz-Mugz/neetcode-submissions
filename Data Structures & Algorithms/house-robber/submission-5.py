class Solution:
    def rob(self, money: List[int]) -> int:
        
        cache = {}

        N = len(money)

        def dfs(index):

            if index >= N: return 0

            if index in cache:
                return cache[index]

            cache[index] = max(money[index] + dfs(index + 2), dfs(index + 1))
            return cache[index]

        return dfs(0)
        