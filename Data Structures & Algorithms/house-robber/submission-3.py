class Solution:
    def rob(self, money: List[int]) -> int:
        
        cache = {}

        N = len(money)

        def dfs(index):

            if index >= N: return 0

            if index in cache:
                return cache[index]

            cache[index] = money[index] + max(dfs(index + 2), dfs(index + 3))
            return cache[index]

        return max(dfs(0), dfs(1))
        